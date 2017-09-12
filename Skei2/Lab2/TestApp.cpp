#include "TestApp.hpp"

TestApp::TestApp()
{
	menu.setMenuTitle("Main menu");
	menu.addItem("Create and manage customer (auto saves current)",true);
	menu.addItem("Manage existing customer (auto saves current)",true);
	menu.addItem("Change customer name",false);
	menu.addItem("Create account",false);
	menu.addItem("Deposit money",false);
	menu.addItem("Withdraw money",false);
	menu.addItem("View accounts",false);
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
		deposit();
		break;
	case 6:
		withdraw();
		break;
	case 7:
		viewAccounts();
		break;
	case 8:
		viewTotalAssets();
		break;
	case 9:
		removeAccount();
		break;
	case 10:    
		return false;
	default:
		std::cout << "Shit...!" << std::endl;
	}
	if (bank.getAmountAccounts()>0)
	{
		menu.enableAll();
	} 
	else
	{
		menu.enable(3);
		menu.enable(4);
	}
   
	return true;
}

void TestApp::createCustomer()
{
	string fName,lName;
	int unguardedId;
	printPrompt("Enter information","create customer",false,false);
	getLine(fName,"First name: ");
	getLine(lName,"Last name : ");
	
	do
	{
		getInt(unguardedId,"Enter personal id: ");
	} while (unguardedId<0);

	const size_t id=unguardedId;
	bank.createCustomer(id,fName,lName);    
}

void TestApp::manageCustomer()
{
	int unguardedId;

	printPrompt("Enter information","create customer",false,false);
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

void TestApp::deposit()
{
	int accountNo;
	double amount;
	std::string Amount;

	getInt(accountNo,"Enter accountNo: ");
	std::cout << "Enter deposit amount: ";
	std::cin >> amount;
	std::cin.get();
	//std::getline(cin,Amount);
	//amount=stof(Amount);

	if(std::cout << "Almost there " << std::endl && bank.deposit(accountNo, amount))
		printPrompt(std::to_string(amount) +" has been deposited into account "+std::to_string(accountNo),"Deposit");
}

void TestApp::withdraw()
{
	int accountNo;
	double amount;
	std::string Amount;
	getInt(accountNo,"Enter accountNo: ");
	std::cout << "Enter deposit amount: ";
	std::getline(cin, Amount);
	amount=stof(Amount);
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
	for (auto & i: *(bank.getAccounts()))
	{
		i->print();
	}
}

void TestApp::viewTotalAssets() const
{
	printPrompt(std::to_string(bank.getTotalAssets()));
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