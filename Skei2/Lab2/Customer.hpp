#ifndef CUSTOMERH
#define CUSTOMERH

#include "Account.hpp"
#include <memory>		// for memory management: std::unique_ptr
#include <vector>	
#include <string>		

class Customer
{
public:
	//constructor and destructor
	Customer(const unsigned int id, std::string firstName="", std::string lastName="");
	~Customer();

	const bool createAccount(const unsigned int accountNo);
	const bool removeAccount(const unsigned int accountNo);
	const bool deposit(const unsigned int accountNo, const double amount);
	const bool withdraw(const unsigned int accountNo, const double amount);
	const bool changeAccountCredit(const unsigned int accountNo, const double amount);
	const bool saveToFile() const;
	const bool loadFromFile();

// get functions.
	const std::string getName() const;
	const unsigned int & getId() const;
	const unsigned int getAmountAccounts() const;
	const std::vector<std::unique_ptr<Account>> & getAllAccounts() const;
	const AccountInfo getAccountInfo(const unsigned int accountNo);
	const double getTotalAssets() const;
	void setName(const std::string fName,const std::string lName);
private:
	// compares iterator to vector.end() to see if result really is found	
	const unsigned int id;
	std::string firstName;
	std::string lastName;
	
	static const unsigned int maxAccounts=3;
	std::vector<std::unique_ptr<Account>> accounts;

	std::vector<std::unique_ptr<Account>>::iterator findAccount(const unsigned int accountNo);
	const bool accountFound(std::vector<std::unique_ptr<Account>>::iterator & found) const;	
};


#endif