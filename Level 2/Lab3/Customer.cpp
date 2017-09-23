#include "Customer.hpp"	//	
#include <fstream>		//	for file manipulation
#include <algorithm> 	// 	for std::find_if()
#include "Functions.hpp"

//constructor and destructor
Customer::Customer(const unsigned int id, std::string fName,std::string lName)
:id(id),firstName(fName),lastName(lName)
{
	//
}

Customer::~Customer()
{
	saveToFile(); //won't lose a save ever.
}


// create an account for customer
const bool Customer::createAccount(const unsigned int accountNo, AccountType type, const double balance, const double credit, const unsigned int withdrawals)
{ 
	if(accounts.size()!=maxAccounts) // if max accounts aren't reached
	{
		if (!accountFound(findAccount(accountNo))) // if accountNo doesn't exits
		{	
			switch(type)
			{
				case NOTYPE:
					// do nothing shouldn't every be used If we'd learned throw errors i'd put one here.
					break;
				case TRANSACTION:
					accounts.push_back(std::unique_ptr<Account>(new TransactionAccount(accountNo,balance,credit))); // create account
					break;	
				case SAVINGS:
					accounts.push_back(std::unique_ptr<Account>(new SavingsAccount(accountNo,balance,withdrawals))); // create account
					break;
				case LONGTERMSAVINGS:
					accounts.push_back(std::unique_ptr<Account>(new LongTermSavingsAccount(accountNo,balance,withdrawals))); // create account 
					break; 
			}
			return true;
		}	
	}              
	return false;
}

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

const bool Customer::deposit(const unsigned int accountNo,const double amount)
{
	// only tries to deposit money if account is found. 
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

//returns wether account is found
const bool Customer::accountFound(std::vector<std::unique_ptr<Account>>::const_iterator found) const
{
	return !(found==accounts.end()); 
}

const bool Customer::changeAccountCredit(const unsigned int accountNo, const double amount)
{
	auto found = findAccount(accountNo); 
	return (accountFound(found)) ? (*found)->setCredit(amount) : false;
}

/*
						get functions for customer
																		*/

const std::string Customer::getName() const 
{
	return firstName+" "+lastName;;
}

const unsigned int Customer::getAmountAccounts() const
{
	return accounts.size();
}

/*
						get functions for accounts
																		*/
const AccountInfo Customer::getAccountInfo(const unsigned int accountNo)
{ 
	auto found = findAccount(accountNo);
	return accountFound(found) ? (*found)->getAccountInfo() : AccountInfo();	  
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

/*
						file manipulation
																		*/
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
	if(is)
	{		
		getline(is,firstName);
		getline(is,lastName); 

		int type,withdrawals;
		double accountNo, balance, credit;

		while(is >> accountNo >> type >> balance >> credit >> withdrawals)
		{
			AccountType typen = static_cast<AccountType>(type);
			createAccount(accountNo,typen,balance,credit,withdrawals);
		}
		return true;
	}
	is.close(); //closing stream
	return false;
}

//returns true if accountNo is assosiated with any account in vector.
const bool Customer::accountExists(const unsigned int accountNo)
{
	return (accountFound(findAccount(accountNo)));
}

// Just set names...
void Customer::setName(const std::string & fName,const std::string & lName)
{
	firstName = fName;
	lastName = lName;
}

//find account in the unique_ptr<accounts> vector and return iterator to it. 
const std::vector<std::unique_ptr<Account>>::const_iterator Customer::findAccount(const unsigned int accountNo) const
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