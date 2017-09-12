#include "Bank.hpp"
#include <iostream>

Bank::Bank()
{
}

Bank::~Bank()
{
}

const bool Bank::saveToFile() const 
{
	//will only write to File if currentCustomer smartptr isn't empty.
	return currentCustomer!=nullptr && currentCustomer->saveToFile();
}

const bool Bank::manageCustomer(const unsigned int id)
{
	currentCustomer.reset(new Customer(id));
	return true;
}

const bool Bank::createCustomer(const unsigned int id, std::string fName, std::string lNam)
{
	currentCustomer.reset(new Customer(id));
	return true;
}

const std::string Bank::getCurrentName() const
{
	return currentCustomer->getName().format();	
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
	return std::cout << "Almost there " << std::endl && currentCustomer->deposit(accountNo, amount);
}

const bool Bank::withdraw(const unsigned int accountNo, const double amount)
{
	return currentCustomer->withdraw(accountNo,amount);
}

const std::array<std::unique_ptr<Account>, 3>* Bank::getAccounts() const
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