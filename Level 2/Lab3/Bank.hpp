#ifndef BANKH
#define BANKH

#include "Customer.hpp"

class Bank
{
public:
	//constructor and destructor.
	Bank();
	~Bank();

	//Customer const non change get Functions
	const bool customerExists() const;
	const std::string getCurrentName() const;

	//Account get const non change functions
	const bool accountExists(const unsigned int accountNo) const;
	const AccountInfo getAccountInfo(const unsigned int accountNo) const;
	const unsigned int getAmountAccounts() const;
	const double getTotalAssets() const;
	const std::vector<std::unique_ptr<Account>> & getAccounts() const;
	
	//file manipulation Functions 
	const bool saveToFile() const;
	const bool manageCustomer(const unsigned int id);
	
	//customer manipulation functions
	const bool createCustomer(const unsigned int id, std::string fName, std::string lNam);
	void changeCurrentName(std::string fName, std::string lName);

	//account manipulation functions	
	const bool changeAccountCredit(const unsigned int accountNo, const double newCredit);
	const bool createAccount(const unsigned int accountNo,AccountType type);
	const bool deposit(const unsigned int accountNo,const double amount);
	const bool withdraw(const unsigned int accountNo, const double amount);
	const bool removeAccount(const unsigned int accountNo);
	
private:
	// should not be accessed outside of classW
	std::unique_ptr <Customer> currentCustomer;
};


#endif