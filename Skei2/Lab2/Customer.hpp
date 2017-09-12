#ifndef CUSTOMERH
#define CUSTOMERH

#include "Account.hpp"
#include <memory>
#include <array>

struct Name
{
	std::string firstName;
	std::string lastName;
	std::string format() const
	{
		return firstName+" "+lastName;
	}
};

struct AccountInfo
{
	double balance;
	double credit;
	double available;
};

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
	//void changeCredir(?);
	const bool saveToFile() const;
	const bool loadFromFile();

// get functions.
	const Name & getName() const;
	const unsigned int & getId() const;
	const unsigned int getAmountAccounts() const;
	const std::array<std::unique_ptr<Account>, 3>* getAllAccounts() const;
	const AccountInfo getAccountInfo(const unsigned int accountNo);
	const double getTotalAssets() const;
	void setName(const std::string fName,const std::string lName);

private:
	static const unsigned int maxAccounts=3;
	const unsigned int id;
	Name name;
	
	std::unique_ptr<Account> * const findAccount(const unsigned int accountNo) ;
//know max amount of accmounts beforehand. Array seems fitting.
	std::array<std::unique_ptr<Account>,maxAccounts> accounts;

	
};


#endif