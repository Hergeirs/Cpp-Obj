#include "Account.hpp"
#include "Functions.hpp"

//Only constructor.
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
	return amount<0 ? false : (balance+=amount); // only changes balance if amount is positive number
}

const bool Account::withdraw(const double amount)
{ 
	// if amount less than zero or amount bigger than usable balance. withrawal is not possible
	return amount <0 || amount > getUsableBalance() ? false : (balance-=amount);
	/*
	if (amount > getUsableBalance())
	{
		return false;
	}
	else
	{
		balance-=amount;
		return true;
	}
	*/
}

const bool Account::setCredit(const double newCredit)
{
	// If the new credit makes usablebalance negative It's not valid
	return newCredit+balance < 0 ? false : (credit=newCredit);
	
	/*
	if(newCredit+balance >= 0) // if usable amount still is good
	{
		return (credit=newCredit);
	}
	else
	{
		return false;
	}
	*/	
}

// regular get functions


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

const AccountInfo Account::getAccountInfo() const
{
	return AccountInfo(accountNo,balance,credit,getUsableBalance());
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
	a >> b.accountNo >> b.balance >> b.credit;
	return a;
} 