#include "Bank.hpp"
#include <iostream>
#include "Functions.hpp"

Bank::Bank()
{
	//
}

Bank::~Bank()
{
	//
}

/*
				const get view only functions
																			*/

const bool Bank::customerExists() const
{
	return currentCustomer!=nullptr;
}

const std::string Bank::getCurrentName() const
{
	return currentCustomer->getName();	
}
/*
							Account gets
																			*/
const bool Bank::accountExists(const unsigned int accountNo) const
{
	return currentCustomer->accountExists(accountNo);
}

const AccountInfo Bank::getAccountInfo(const unsigned int accountNo) const
{
	return currentCustomer->getAccountInfo(accountNo);
}

const unsigned int Bank::getAmountAccounts() const
{
	return currentCustomer->getAmountAccounts();
}

const double Bank::getTotalAssets() const
{
	return currentCustomer->getTotalAssets();
}

const std::vector<std::unique_ptr<Account>>& Bank::getAccounts() const
{
	return currentCustomer->getAllAccounts();	
}

/*
				Functions to write/read from/to file
																			*/
const bool Bank::saveToFile() const 
{ 
	//will only write to File if currentCustomer smartptr isn't empty.
	return currentCustomer!=nullptr && currentCustomer->saveToFile();
}

const bool Bank::manageCustomer(const unsigned int id)
{
	if (fileExist(std::to_string(id)+".knt"))
	{
		currentCustomer.reset(new Customer(id)); // destructs old customer create new Customer object.
		return currentCustomer->loadFromFile();	 // load info from file returns false if file doesn't exist.
	}
	return false;
}

/*
			Functions to manipulate current customer object
																			*/
const bool Bank::createCustomer(const unsigned int id, std::string fName, std::string lName)
{
	if (!(fileExist(std::to_string(id)+".knt")))
	{	
		currentCustomer.reset(new Customer(id,fName,lName));
		return true;
	}
	return false;
}

void Bank::changeCurrentName(std::string fName, std::string lName)
{
	currentCustomer->setName(fName,lName);
}


/*
				Functions to implement account Functions	
																			*/
const bool Bank::createAccount(const unsigned int accountNo,AccountType type)
{
	return currentCustomer->createAccount(accountNo,type);
}

const bool Bank::changeAccountCredit(const unsigned int accountNo, const double newCredit)
{
	return currentCustomer->changeAccountCredit(accountNo,newCredit);
}

const bool Bank::removeAccount(const unsigned int accountNo)
{
	return currentCustomer->removeAccount(accountNo);
}

const bool Bank::deposit(const unsigned int accountNo,const double amount)
{
	return currentCustomer->deposit(accountNo, amount);
}

const bool Bank::withdraw(const unsigned int accountNo, const double amount)
{
	return currentCustomer->withdraw(accountNo,amount);
}