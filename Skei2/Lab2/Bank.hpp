#ifndef BANKH
#define BANKH

#include "Customer.hpp"

class Bank
{
public:
	Bank();
	~Bank();
	const bool saveToFile() const;
	const bool manageCustomer(const unsigned int id);
	const bool createCustomer(const unsigned int id, std::string fName, std::string lNam);
	const std::string getCurrentName() const;
	void changeCurrentName(std::string fName, std::string lName);
	const unsigned int getAmountAccounts() const;
	const bool createAccount(const unsigned int accountNo);
	const bool deposit(const unsigned int accountNo,const double amount);
	const bool withdraw(const unsigned int accountNo, const double amount);
	const std::array<std::unique_ptr<Account>, 3>* getAccounts() const;
	const double getTotalAssets() const;
	const bool removeAccount(const unsigned int accountNo);
private:
	std::unique_ptr <Customer> currentCustomer;
};


#endif