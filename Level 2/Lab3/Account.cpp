#include "Account.hpp"
#include "Functions.hpp"

//Only constructor.
Account::Account(const unsigned int pAccountNo, const double pBalance, const AccountType pAccountType)
:type(pAccountType),accountNo(pAccountNo),balance(pBalance)
{
	//
}

Account::~Account()
{
	//Nothing to do here.
}

const bool Account::deposit(const double amount)
{
	// only changes balance if amount is positive number
	return amount<0 ? false : (balance+=amount); 
}

const bool Account::withdraw(const double amount)
{ 
	// if amount bigger than usable balance. withrawal is not possible
	return amount > getUsableBalance() ? false : (balance-=amount);
}

const bool Account::setCredit(const double newCredit)
{
	// If the new credit makes usablebalance negative It's not valid
	return 0;
}

const bool Account::setInterest(const double amount)
{
	return 0;
}

// regular get functions


const double Account::getInterest() const
{
	return 0.0;
}

const double Account::getCredit() const
{
	return 0.0;
}

const double & Account::getBalance() const
{
	return balance;
}

const double Account::getUsableBalance() const
{
	return balance+getCredit();
}

const unsigned int & Account::getAccountNo() const
{
	return accountNo;	
}
// this function will follow to the other classes and give correct values for all.
const AccountInfo Account::getAccountInfo() const 
{
	return AccountInfo(accountNo,getTypeText(),balance,getCredit(),getInterest(),getUsableBalance());
} 

const unsigned int Account::getWithdrawals() const
{
	return 0;
}

const std::string Account::getTypeText() const 
{
	switch(type)	// type is enum and all possible cases are covered below
	{
		case NOTYPE:
			break;
		case TRANSACTION:
			return "Transaction Account";
		case SAVINGS:
			return "Savings Account";
		case LONGTERMSAVINGS:
			return "Long Term Savings Account";	
	}
	return "ERROR NO TYPE! BASECLASS USED!";
}

const AccountType & Account::getType() const
{
	return type;
}

/*************************************************************************
	Overloaded operators for class 
**************************************************************************/
std::ostream & operator << (std::ostream & a, const Account & b)
{
	a << b.getAccountNo() << std::endl << b.getType() << std::endl << b.getBalance() << std::endl << b.getCredit() << std::endl << b.getWithdrawals() << std::endl;

	return a;
}
