#ifndef ACCOUNTH
#define ACCOUNTH

#include <fstream>
#include <memory>
#include <string>

//for easy output and display of accountInfo

struct AccountInfo
{
	const unsigned int accountNo;
	const std::string accountType;
	const double balance;
	const double credit;
	const double interest;
	const double available;
	//default constructor
	AccountInfo()
	:accountNo(0),balance(0),credit(0),interest(0),available(0){}
	//constructor
	AccountInfo(const unsigned int pAccountNo,const std::string & pAccountType,const double pBalance, const double pCredit, const double pInterest, const double pAvailable)
	:accountNo(pAccountNo),accountType(pAccountType),balance(pBalance),credit(pCredit),interest(pInterest),available(pAvailable){}
};

//for account types	
enum AccountType
{
	NOTYPE ,
	TRANSACTION ,
	SAVINGS ,
	LONGTERMSAVINGS
};

class Account
{
public:
	//Constuctor. default values for balance and credit
	Account(const unsigned int pAccountNo=0, const double pBalance=0,const AccountType pAccountType=NOTYPE);
	virtual ~Account();
	
	const bool deposit(const double amount);
	virtual const bool withdraw(const double amount);
	virtual const bool setCredit(const double amount);
	virtual const bool setInterest(const double amount);
	virtual const double getInterest() const;
	virtual const double getCredit() const;         	//get current credit for account
	const double & getBalance() const;        			//get current balance for account
	virtual const double getUsableBalance() const;  	//get balance + credit
	const unsigned int & getAccountNo() const;			//get accountNo
	const AccountInfo getAccountInfo() const;			//get all info at once

protected:
	const AccountType type;		// enum of accountType
	unsigned int accountNo;
	double balance;
	virtual const unsigned int getWithdrawals() const;
	const std::string getTypeText() const;
	const AccountType getType() const;
	const bool setType(const AccountType accountType); // make this protected for safety
	

	friend std::ostream & operator << (std::ostream & a, const Account & b);
	//friend std::istream & operator >> (std::istream & a, Account & b);
};

std::ostream & operator << (std::ostream & a, const Account & b);
//std::istream & operator >> (std::istream & a, Account & b);

#endif