#include "Bank.hpp"
#include <iostream>

Bank::Bank()
{
	//
}

Bank::~Bank()
{
	//
}

const bool Bank::customerExists() const
{
	return currentCustomer!=nullptr;
}

const bool Bank::accountExists(const unsigned int accountNo) const
{
	return currentCustomer->accountExists(accountNo);
}

const AccountInfo Bank::getAccountInfo(const unsigned int accountNo) const
{
	return currentCustomer->getAccountInfo(accountNo);
}

const bool Bank::saveToFile() const 
{ 
	//will only write to File if currentCustomer smartptr isn't empty.
	return currentCustomer!=nullptr && currentCustomer->saveToFile();
}

const bool Bank::manageCustomer(const unsigned int id)
{
	currentCustomer.reset( new Customer(id)); // create new Customer object.
	return currentCustomer->loadFromFile();	 // load info from file returns false if file doesn't exist.
}

const bool Bank::createCustomer(const unsigned int id, std::string fName, std::string lName)
{
	if (!(Customer(id).loadFromFile()))
	{	
		currentCustomer.reset(new Customer(id,fName,lName));
		return true;
	}
	return false;
}

const std::string Bank::getCurrentName() const
{
	return currentCustomer->getName();	
}

const bool Bank::changeAccountCredit(const unsigned int accountNo, const double newCredit)
{
	return currentCustomer->changeAccountCredit(accountNo,newCredit);
}

void Bank::changeCurrentName(std::string fName, std::string lName)
{
	currentCustomer->setName(fName,lName);
}

const unsigned int Bank::getAmountAccounts() const
{
	return currentCustomer->getAmountAccounts();
}

const bool Bank::createAccount(const unsigned int accountNo)
{
	return currentCustomer->createAccount(accountNo);
}

const bool Bank::deposit(const unsigned int accountNo,const double amount)
{
	return currentCustomer->deposit(accountNo, amount);
}

const bool Bank::withdraw(const unsigned int accountNo, const double amount)
{
	return currentCustomer->withdraw(accountNo,amount);
}

const std::vector<std::unique_ptr<Account>>& Bank::getAccounts() const
{
	return currentCustomer->getAllAccounts();	
}

const double Bank::getTotalAssets() const
{
	return currentCustomer->getTotalAssets();
}

const bool Bank::removeAccount(const unsigned int accountNo)
{
	return currentCustomer->removeAccount(accountNo);
}