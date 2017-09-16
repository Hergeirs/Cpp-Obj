#include "Customer.hpp"	//	
#include <fstream>		//	for file manipulation
#include <algorithm> 	// 	for std::find_if()

Customer::Customer(const unsigned int id, std::string fName,std::string lName)
:id(id)
{
	firstName=fName;
	lastName=lName;
}

Customer::~Customer()
{
	saveToFile(); //won't lose a save ever.
}

// create an account for customer
const bool Customer::createAccount(const unsigned int accountNo)
{
	if(accounts.size()!=maxAccounts) // if max accounts aren't reached
	{
		if (!accountFound(findAccount(accountNo))) // if accountNo doesn't exits
		{	
			accounts.push_back(std::unique_ptr<Account>(new Account(accountNo))); // create account
			return true;
		}
	}              
	return false;
}

/*
if i didn't want bool return from removeAccount function i'd have used this beauty:
void Customer::removeAccount(const unsigned int accountNo)	
	accounts.erase(std::remove_if(accounts.begin(),accounts.end(),
	[& accountNo](const Account & a)
	{
		return a.getAccountNo == accountNo;
	}));
*/

// remove account with accountNo from accounts vector
const bool Customer::removeAccount(const unsigned int accountNo)
{   
	auto found = findAccount(accountNo);
	if (accountFound(found))
	{   
		accounts.erase(found); // removes found and thereby calls delete on smartpointer
		return true;
	}
	return false;
}

// only tries to deposits money if account is found. 
const bool Customer::deposit(const unsigned int accountNo,const double amount)
{
	auto found = findAccount(accountNo);
	if(accountFound(found))
	{ 
		return ((*found)->deposit(amount));
	}
	return false;
}

const bool Customer::withdraw(const unsigned int accountNo,const double amount)
{
	auto found = findAccount(accountNo);
	if(accountFound(found))
	{
		if((*found)->withdraw(amount))
		{
			return true;
		}
	}
	return false;
}

const bool Customer::accountFound(std::vector<std::unique_ptr<Account>>::iterator found) const
{
	return !(found==accounts.end()); 
}

 

const bool Customer::changeAccountCredit(const unsigned int accountNo, const double amount)
{
	auto found = findAccount(accountNo); 
	return (accountFound(found)) ? (*found)->setCredit(amount) : false;
	/*
	if (accountFound(found))
	{
		return (*found)->setCredit(amount);
	}
	else
	{
		return false;
	}
	*/
}

const std::string Customer::getName() const 
{
	return firstName+" "+lastName;;
}

const unsigned int & Customer::getId() const 
{
	return id;
}

const unsigned int Customer::getAmountAccounts() const
{
	return accounts.size();
}

const AccountInfo Customer::getAccountInfo(const unsigned int accountNo)
{
	auto found = findAccount(accountNo);
	return accountFound(found) ? (*found)->getAccountInfo() : AccountInfo();
	
	/*
	if(accountFound(found))
	{
		return (*found)->getAccountInfo();
	}
	return {0,0,0}; 
	*/  
}

const double Customer::getTotalAssets() const
{
	double total=0;
	for(auto & i: accounts)
	{
		total+=i->getBalance();
	}
	return total;
}

const bool Customer::saveToFile() const
{
	std::ofstream os(std::to_string(id)+".knt"); 
	if(os.is_open())
	{	
		os << firstName << std::endl << lastName << std::endl;
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
		getline(is,firstName);
		getline(is,lastName); 
		Account account;
		// sorry about splitting the lines below. But it was simply to confusing otherwise
		while (is >> account)
		{
			accounts.push_back(std::unique_ptr<Account>(new Account(account.getAccountNo(),account.getBalance(),account.getCredit())));
		}
		is.close(); //closing stream
		return true;
	}
	return false;
}

// Just set names...
void Customer::setName(const std::string fName,const std::string lName)
{
	firstName = fName;
	lastName = lName;
}

//returns true if accountNo is assosiated with any account in vector.
const bool Customer::accountExists(const unsigned int accountNo)
{
	return (accountFound(findAccount(accountNo)));
}

//find account in the unique_ptr<accounts> vector and return iterator to it.
std::vector<std::unique_ptr<Account>>::iterator Customer::findAccount(const unsigned int accountNo)
{
	return std::find_if(accounts.begin(),accounts.end(),[&accountNo]
	(const std::unique_ptr<Account> & a)
	{ 
		return ((a->getAccountNo())==accountNo);
	});
} 
 
 //Return const vector reference to accountss
const std::vector<std::unique_ptr<Account>> & Customer::getAllAccounts() const
{
	return accounts; 
}