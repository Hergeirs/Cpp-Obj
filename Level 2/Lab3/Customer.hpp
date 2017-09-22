#ifndef CUSTOMERH
#define CUSTOMERH

#include "Accounts.hpp"
#include <memory>		// for memory management: std::unique_ptr
#include <vector>	
#include <string>		

class Customer
{
public:
	//constructor and destructor
	Customer(const unsigned int id, std::string firstName="", std::string lastName="");
	~Customer();

	//account manipulation functions
	const bool createAccount(const unsigned int accountNo, AccountType type, const double balance=0, const double credit=0, const unsigned int withdrawals=0);
	const bool removeAccount(const unsigned int accountNo);
	const bool deposit(const unsigned int accountNo, const double amount);
	const bool withdraw(const unsigned int accountNo, const double amount);
	const bool changeAccountCredit(const unsigned int accountNo, const double amount);
	
	//file manipulation	
	const bool saveToFile() const;
	const bool loadFromFile();

	//get functions for customer.
	const std::string getName() const;
	const unsigned int & getId() const;
	
	//get functions for accounts.
	const unsigned int getAmountAccounts() const;
	const std::vector<std::unique_ptr<Account>> & getAllAccounts() const;
	const AccountInfo getAccountInfo(const unsigned int accountNo);
	const double getTotalAssets() const;
	const bool accountExists(const unsigned int accountNo);
	
	//customer manipulation functions
	void setName(const std::string & fName,const std::string & lNafme);

	
private:
	const unsigned int id;
	std::string firstName;
	std::string lastName;
	
	static const unsigned int maxAccounts=3;
	std::vector<std::unique_ptr<Account>> accounts;

	const std::vector<std::unique_ptr<Account>>::const_iterator findAccount(const unsigned int accountNo) const;
	const bool accountFound(std::vector<std::unique_ptr<Account>>::const_iterator found) const;	
};


#endif