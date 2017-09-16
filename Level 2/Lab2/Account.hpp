#ifndef ACCOUNTH
#define ACCOUNTH

#include <fstream>


//for easy output and display of accountInfo
struct AccountInfo
{
	const unsigned int accountNo;
	const double balance;
	const double credit;
	const double available;
	//default constructor
	AccountInfo()
	:accountNo(0),balance(0),credit(0),available(0){}
	//constructor
	AccountInfo(const unsigned int pAccountNo,const double pBalance, const double pCredit, const double pAvailable)
	:accountNo(pAccountNo),balance(pBalance),credit(pCredit),available(pAvailable){}
};



class Account
{
public:
	//Constuctor. default values for balance and credit
	Account(const unsigned int pAccountNo=0, const double pBalance=0, const double pCredit=0);
	~Account();
	
	const bool deposit(const double amount);
	const bool withdraw(const double amount);
	const bool setCredit(const double amount);
	const double & getCredit() const;         	//get current credit for account
	const double & getBalance() const;        	//get current balance for account
	const double getUsableBalance() const;  	//get balance + credit
	const unsigned int & getAccountNo() const;	//get accountNo
	const AccountInfo getAccountInfo() const;	// get all info at once

private:
	unsigned int accountNo;
	double balance;
	double credit;
	
	friend std::ostream & operator << (std::ostream & a, const Account & b);
	friend std::istream & operator >> (std::istream & a, Account & b);
};

std::ostream & operator << (std::ostream & a, const Account & b);
std::istream & operator >> (std::istream & a, Account & b);

#endif