#include "Account.hpp"
#include "Functions.hpp"

Account::Account(const unsigned int pAccountNo, const double pBalance, const double pCredit)
:accountNo(pAccountNo)
{
	balance = pBalance;
	credit = pCredit;
}

Account::~Account()
{
	//Nothing to do here.
}

const bool Account::deposit(const double amount)
{
	balance+=amount;
	return true;
}

const bool Account::withdraw(const double amount)
{
	if (amount > getUsableBalance())
	{
		return false;
	}
	else
	{
		balance-=amount;
		return true;
	}
}

void Account::changeCredit(const double amount)
{
	credit=amount;
}

const double & Account::getCredit() const
{
	return credit;
}

const double & Account::getBalance() const
{
	return balance;
}

const double Account::getUsableBalance() const
{
	return balance+credit;
}

const unsigned int & Account::getAccountNo() const
{
	return accountNo;	
}

void Account::print() const
{
	printPrompt("Balance: "+std::to_string(balance),std::to_string(accountNo));
}

Account Account::operator= (const Account & b)
{
	return Account(b.accountNo,b.balance,b.credit);
}

/*************************************************************************
	Overloaded operators for class friended them to surpass get functions.
**************************************************************************/
std::ostream & operator << (std::ostream & a, const Account & b)
{
	a << b.accountNo << std::endl << b.balance << std::endl << b.credit << std::endl;
	return a;
}
std::istream & operator >> (std::istream & a, Account & b)
{
	unsigned int accountNo;
	double balance;
	double credit;
	a >> accountNo >> balance >> credit;
	b=Account(accountNo,balance,credit);
	return a;
} 