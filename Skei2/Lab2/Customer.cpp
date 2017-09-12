#include "Customer.hpp"
#include <fstream>
#include <iostream>

Customer::Customer(const unsigned int id, std::string pFirstName,std::string pLastName)
:id(id)
{
	name = {pFirstName,pLastName};
}

Customer::~Customer()
{
	saveToFile() && std::cout << "what";
}

const bool Customer::createAccount(const unsigned int accountNo)
{
	std::cout << getAmountAccounts() << std::endl;
	const unsigned int size = getAmountAccounts();
	if(size!=maxAccounts)
	{
		std::unique_ptr<Account> temp(new Account(accountNo));
		accounts[size-1] = std::move(temp);
		return true;
	}              
	return false;
}

const bool Customer::removeAccount(const unsigned int accountNo)
{   
	auto found = findAccount(accountNo);
	if (found != nullptr)
	{
		found->reset(nullptr);
		return true;
	}
	return false;
}

const bool Customer::deposit(const unsigned int accountNo,const double amount)
{
	std::cout << "Almost there " << std::endl;
	auto found = findAccount(accountNo);
	if(found != nullptr)
	{
		if((*found)->deposit(amount))
		{
			return true;
		}
	}
	return false;
}

const bool Customer::withdraw(const unsigned int accountNo,const double amount)
{
	auto found = findAccount(accountNo);
	if(found != nullptr)
	{
		if((*found)->withdraw(amount))
		{
			return true;
		}
	}
	return false;
}

const Name & Customer::getName() const 
{
	return name;
}

const unsigned int & Customer::getId() const 
{
	return id;
}

const unsigned int Customer::getAmountAccounts() const
{
	unsigned int amount=0;
	unsigned int count=0;
	for (auto & i: accounts)
	{
		std::cout << count++ << std::endl;
		if (i!=nullptr)
		{
			std::cout << count << std::endl;
			++amount;
		}
	}
	std::cout << amount << std::endl;
	return amount;
}

const AccountInfo Customer::getAccountInfo(const unsigned int accountNo)
{
	auto found = findAccount(accountNo);
	if(found!=nullptr)
	{
		AccountInfo a = 
		{
			(*found)->getBalance(),
			(*found)->getCredit(),
			(*found)->getUsableBalance()
		};
		return a;
	}
	return {0,0,0};   
}

const double Customer::getTotalAssets() const
{
	double total=0;
	for(auto & i: accounts)
	{
		total+=i->getUsableBalance();
	}
	return total;
}

const bool Customer::saveToFile() const
{
	std::ofstream os(std::to_string(id)+".knt"); 
	if(os.is_open())
	{	
		os << name.firstName << std::endl << name.lastName << std::endl;
		for (auto & i: accounts)
		{
			os << *i;
		}
		os.close();
		return true;
	}
	return false;
}

const bool Customer::loadFromFile()
{
	std::ifstream is(std::to_string(id)+".knt");
	if(is.is_open())
	{	
		
		getline(is,name.firstName);
		getline(is,name.lastName); 
		Account account;
		
		size_t i=0;
		while (is >> account)
		{
			 accounts[i++].reset(new Account());
			 *accounts[i]=account;
		}
		is.close();
		return true;
	}
	return false;
}

void Customer::setName(const std::string fName,const std::string lName)
{
	name.firstName = fName;
	name.lastName = lName;
}

std::unique_ptr<Account> * const Customer::findAccount(const unsigned int accountNo)
{
	std::cout << "so far so good!" << std::endl;
	for(auto & i: accounts)
	{
		if(i!=nullptr && std::cout << i->getAccountNo() && i->getAccountNo()==accountNo)
		{
			i->print();
			return &i;
		}
	}
	return nullptr;
}

const std::array<std::unique_ptr<Account>, 3>* Customer::getAllAccounts() const
{
	return &accounts;
}