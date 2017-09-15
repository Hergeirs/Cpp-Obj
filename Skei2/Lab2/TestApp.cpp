#include "TestApp.hpp"
#include <iostream>
#include <iomanip>

// default constructor.

const unsigned int TestApp::getAccountNo() const
{
	unsigned int accountNo;
	do
	{
		accountNo = getUnsignedInt("Enter account number: ");
	} while (!bank.accountExists(accountNo) && printPrompt("account "+std::to_string(accountNo)+" does not exist")); // while account doesn't exist	
	return accountNo;
}


TestApp::TestApp()
{
	menu.setMenuTitle("Main menu");
	menu.addItem("Create and manage customer (auto saves current)",true);
	menu.addItem("Manage existing customer (auto saves current)",true);
	menu.addItem("Change customer name",false);
	menu.addItem("Create account",false);
	menu.addItem("Change account credit",false);
	menu.addItem("Deposit money",false);
	menu.addItem("Withdraw money",false);
	menu.addItem("View accounts",false);
	menu.addItem("View specific account",false);
	menu.addItem("View total Assets",false);
	menu.addItem("Remove account",false);
	menu.addItem("Quit",true);
}

TestApp::~TestApp()
{
	//I have nothing
}

void TestApp::run()
{
	while (doMenuChoice(menu.getMenuChoice())){} // will loop until doMenuChoice returns false
}

// call relevant functions.
const bool TestApp::doMenuChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		createCustomer();
		break;
	case 2:
		manageCustomer();
		break;
	case 3:
		changeCustomerName();
		break;
	case 4:
		createAccount();
		break;
	case 5:
		changeAccountCredit();
		break;
	case 6:
		deposit();
		break;
	case 7:
		withdraw();
		break;
	case 8:
		viewAccounts();
		break;
	case 9:
		viewAccount();
		break;
	case 10:
		viewTotalAssets();
		break;
	case 11:
		removeAccount();
		break;
	case 12:    
		return false;
	default:
		break;

	}
	if(bank.customerExists()) // customer must exist for menus to show.
	{
		if (bank.getAmountAccounts()>0)
		{
			menu.enableAll(); 
		} 
		else 
		{
			menu.disableAll(); // removes all menuItems except exit/quit.
			for(int i=1; i<5; ++i)
				menu.enable(i); //enabling relevant menus
		}
	}	
	return true;
}

void TestApp::createCustomer()
{
	std::string fName,lName;
	printPrompt("Enter information","create customer",false,false);
	const unsigned int id = getUnsignedInt("Enter customer id: ");
	getLine(fName,"First name: ");
	getLine(lName,"Last name : ");
	if(bank.createCustomer(id,fName,lName))
	{
		printPrompt("Customer "+bank.getCurrentName()+" was created, with id:"+std::to_string(id),"create customer");
	}
	else
	{
		printPrompt("Customer with id:"+std::to_string(id)+" already exists... Try manage customer.","error");
	}
}

void TestApp::manageCustomer()
{
	printPrompt("Enter information","Manage customer",false,false);
	unsigned int id = getUnsignedInt("Enter personal id: ");
	if(bank.manageCustomer(id))
	{
		printPrompt(bank.getCurrentName()+" was loaded.");
	}
	else
	{
		printPrompt("No one with id exist in database. did you mean to create user?");
	}
}

void TestApp::changeCustomerName()
{
	std::string fName, lName;
	getLine(fName,"Enter Firstname: ");
	getLine(lName,"Enter Lastname : ");
	bank.changeCurrentName(fName,lName); // don't need bool here. should always work...
	printPrompt("name has been updated to: "+bank.getCurrentName());
}

void TestApp::createAccount()
{
	unsigned int accountNo = getUnsignedInt("Please enter account No: ");
	if (!bank.createAccount(accountNo))
	{
		printPrompt("user already has used accountNo "+std::to_string(accountNo)+" or reached his maximum of 3 accounts");
	}
}

void TestApp::changeAccountCredit()
{
	
	printPrompt("Current Info: ","Change credit",false,false);
	const unsigned int accountNo = getAccountNo();
	printAccountInfo(accountNo); 
	double newCredit = getUnsignedInt("Enter new credit for account: ");
	while (!bank.changeAccountCredit(accountNo,newCredit))
	{
		printPrompt("credit can't be changed to "+std::to_string(newCredit)+" as it would give negative usable balance.");
		newCredit=getUnsignedInt("Enter new credit for account: ");
	}
	printPrompt("account credit for account "+std::to_string(accountNo)+" changed to "+std::to_string(newCredit));	
}


/*
void	TestApp::changeAccountCredit()
{
	std::string newCreditString;
	unsigned int accountNo;
	do
	{
		accountNo = getUnsignedInt("Enter account number: ");
	} while (!accountExist(accountNo) && printPrompt("account "+std::to_string(accountNo)+" does not exist")); // while account doesn't exist
	
	printPrompt("Current Info: ","Change credit");
	printAccountInfo(accountNo); 
	unsigned int newCredit = getUnsignedInt("Enter new credit for account: ");
	
	while (!bank.changeAccountCredit(accountNo,newCredit))
	{
		printPrompt("credit can't be changed to "+std::to_string(newCredit)+" as it would give negative usable balance.");
		newCredit=getUnsignedInt("Enter new credit for account: ");
	}
	printPrompt("account credit for account "+std::to_string(accountNo)+" changed to "+std::to_string(newCredit));	
}
*/

void TestApp::deposit()
{
	const unsigned int accountNo = getAccountNo();
	double amount = getPositiveDouble("Enter deposit amount: ");

	if(bank.deposit(accountNo, amount))
	{
		printPrompt(std::to_string(amount) +" has been deposited into account "+std::to_string(accountNo),"Deposit");
	}
	else
	{
		printPrompt(std::to_string(accountNo)+" does not exist/is not owned by"+bank.getCurrentName());
	}
}

void TestApp::withdraw()
{
	
	const unsigned int accountNo = getAccountNo();
	double amount = getPositiveDouble("Enter withdraw amount");
	if (bank.withdraw(accountNo, amount))
	{
		printPrompt(std::to_string(amount) +" was withdrawn from account "+std::to_string(accountNo),"Withdraw");
	}
	else
	{
		printPrompt("No money was withdrawn from account because of lack of credit","Withdraw");
	}
}

void TestApp::viewAccounts() const
{
	for (auto & i: bank.getAccounts())
	{ 
		printAccountInfo(i->getAccountInfo(),false,false);
	}
	systemPause();
}

void TestApp::viewAccount() const
{	
	printAccountInfo(getAccountNo());
}

void TestApp::viewTotalAssets() const
{
	printPrompt("Total assets: "+std::to_string(bank.getTotalAssets()));
}

void TestApp::removeAccount()
{   
	const unsigned int accountNo = getAccountNo();
	if (bank.removeAccount(accountNo))
	{
		printPrompt(accountNo+" was deleted from customer.");
	}
	else
	{
		printPrompt(accountNo+" does not exist/is not owned by "+bank.getCurrentName());
	}
}



void TestApp::printAccountInfo(const AccountInfo info,const bool pause, const bool clear) const
{
	const size_t width=20;
	printPrompt(std::to_string(info.accountNo),"AccountNo",false,clear,width);
	printPrompt(std::to_string(info.balance),"Balance:",false,false,width);	
	printPrompt(std::to_string(info.credit),"Credit:",false,false,width);
	printPrompt(std::to_string(info.available),"Usable balance",pause,false,width);
	std::cout << std::endl;
} 

void TestApp::printAccountInfo(const unsigned int accountNo) const
{		 
	printAccountInfo(bank.getAccountInfo(accountNo));
}
