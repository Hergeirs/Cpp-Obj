#ifndef ACCOUNTH
#define ACCOUNTH

#include <fstream>

struct AccountInfo
{
	unsigned int accountNo;
	double balance;
	double credit;
	double available;
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