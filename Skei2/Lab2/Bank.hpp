#ifndef BANKH
#define BANKH

#include "Customer.hpp"

class Bank
{
public:
	Bank();
	~Bank();
	const AccountInfo getAccountInfo(const unsigned int accountNo) const;
	const bool saveToFile() const;
	const bool manageCustomer(const unsigned int id);
	const bool createCustomer(const unsigned int id, std::string fName, std::string lNam);
	const std::string getCurrentName() const;
	void changeCurrentName(std::string fName, std::string lName);
	const bool changeAccountCredit(const unsigned int accountNo, const double newCredit);
	const unsigned int getAmountAccounts() const;
	const bool createAccount(const unsigned int accountNo);
	const bool deposit(const unsigned int accountNo,const double amount);
	const bool withdraw(const unsigned int accountNo, const double amount);
	const std::vector<std::unique_ptr<Account>> & getAccounts() const;
	const double getTotalAssets() const;
	const bool removeAccount(const unsigned int accountNo);
private:
	std::unique_ptr <Customer> currentCustomer;
};


#endif