#ifndef ACCOUNTH
#define ACCOUNTH

#include <fstream>
#include <memory>
#include <string>


//for account types	
enum AccountType
{
	NOTYPE ,
	TRANSACTION ,
	SAVINGS ,
	LONGTERMSAVINGS
};

//for easy output and display of accountInfo
struct AccountInfo
{
	const unsigned int accountNo;
	const AccountType type;
	const std::string accountType;
	const double balance;
	const double credit;
	const double interest;
	const double available;
	//default constructor
	AccountInfo()
	:accountNo(0),type(NOTYPE),balance(0),credit(0),interest(0),available(0){}
	//constructor
	AccountInfo(const unsigned int & pAccountNo,const  AccountType & tType,const std::string & pAccountType,const double pBalance, const double pCredit, const double pInterest, const double pAvailable)
	:accountNo(pAccountNo),type(tType),accountType(pAccountType),balance(pBalance),credit(pCredit),interest(pInterest),available(pAvailable){}
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
	virtual const double getInterest() const;
	virtual const double getCredit() const;         	//get current credit for account
	const double & getBalance() const;        			//get current balance for account
	virtual const double getUsableBalance() const;  	//get balance + credit
	const unsigned int & getAccountNo() const;			//get accountNo
	const AccountInfo getAccountInfo() const;			//get all info at once
	const AccountType & getType() const;
	virtual const unsigned int getWithdrawals() const;
	

protected:
	const AccountType type;								// enum of accountType
	unsigned int accountNo;
	double balance;
	const std::string getTypeText() const;
	const bool setType(const AccountType accountType); // make this protected for safety
	
};

std::ostream & operator << (std::ostream & a, const Account & b);


#endif