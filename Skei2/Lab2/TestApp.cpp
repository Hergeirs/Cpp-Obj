#include "TestApp.hpp"

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
	//
}

void TestApp::run()
{
	while (doMenuChoice(menu.getMenuChoice())){}
}

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
	if (bank.getAmountAccounts()>0)
	{
		menu.enableAll();
	} 
	else 
	{
		menu.disableAll();
		for(int i=1; i<5; ++i)
			menu.enable(i); //enabling relevant menus
	}
	return true;
}

void TestApp::createCustomer()
{
	std::string fName,lName;
	int unguardedId;
	printPrompt("Enter information","create customer",false,false);
	getLine(fName,"First name: ");
	getLine(lName,"Last name : ");
	
	do
	{
		getInt(unguardedId,"Enter personal id: ");
	} while (unguardedId<0);

	const size_t id=unguardedId;
	if(bank.createCustomer(id,fName,lName))
	{
		printPrompt("Customer "+bank.getCurrentName()+" was created.","create customer");
	}
	else
	{
		printPrompt("Customer "+bank.getCurrentName()+" already exists. Try manage customer.","error");
	}
}

void TestApp::manageCustomer()
{
	int unguardedId;

	printPrompt("Enter information","Manage customer",false,false);
	  do
	{
		getInt(unguardedId,"Enter personal id: ");
	} while (unguardedId<0);
	const size_t id=unguardedId;
	if(bank.manageCustomer(id))
	{
		printPrompt(bank.getCurrentName()+" was loaded.");
	}
	else
	{
		printPrompt("No one with id exist in database\n did you mean to create user?");
	}
}

void TestApp::changeCustomerName()
{
	std::string fName, lName;
	getLine(fName,"Enter Firstname: ");
	getLine(lName,"Enter Lastname : ");
	bank.changeCurrentName(fName,lName);
	printPrompt("name has been updated to: "+bank.getCurrentName());
}

void TestApp::createAccount()
{
	int accountNo;
	getInt(accountNo,"Please enter account No: ");
	bank.createAccount(accountNo);
}

void	TestApp::changeAccountCredit()
{
	std::string newCreditString;
	int accountNo;
	getInt(accountNo,"Enter account number: ");
	printPrompt("Current Info: ","Change credit");
	printAccountInfo(accountNo); 
	getLine(newCreditString,"Enter new credit for account: "); 
}


void TestApp::deposit()
{
	int accountNo;
	double amount;
	std::string Amount;

	getInt(accountNo,"Enter accountNo: ");
	std::cout << "Enter deposit amount: ";
	std::getline(std::cin,Amount);
	amount=stof(Amount);

	if(std::cout << "Almost there " << std::endl && bank.deposit(accountNo, amount))
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
	int accountNo;
	double amount;
	std::string Amount;
	getInt(accountNo,"Enter accountNo: ");
	std::cout << "Enter amount to withdraw: ";
	std::getline(std::cin, Amount);
	amount=stod(Amount);
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
	int accountNo;
	getInt(accountNo,"Enter account number to view info");
	printAccountInfo(accountNo);
}

void TestApp::viewTotalAssets() const
{
	printPrompt("Total assets: "+std::to_string(bank.getTotalAssets()));
}

void TestApp::removeAccount()
{   
	std::string account;
	getLine(account,"Enter account number to delete: ");
	const unsigned int accountNo = stof(account);
	if (bank.removeAccount(accountNo))
	{
		printPrompt(account+" was deleted from customer.");
	}
	else
	{
		printPrompt(account+" does not exist/is not owned by"+bank.getCurrentName());
	}
}