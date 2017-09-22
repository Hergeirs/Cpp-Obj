#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const unsigned int accountNo, const double balance, const unsigned int pWithdrawals)
:Account(accountNo,balance,SAVINGS),maxWithdrawals(4),withdrawals(pWithdrawals)
{
	interest = 0.02;
}

//PROTECTED initializer
SavingsAccount::SavingsAccount(const unsigned int accountNo, const double balance, const AccountType accountType, const unsigned int pWithdrawals, const unsigned int pMaxWithdrawals)
:Account(accountNo,balance,accountType),maxWithdrawals(pMaxWithdrawals),withdrawals(pWithdrawals)
{
	interest = 0.02;
}

const bool SavingsAccount::withdraw(const double amount)
{
	if (maxWithdrawals < ++withdrawals || amount > balance)
	{ 
		return false;
	}
	else
	{
		return (balance-=amount);
	}
}

const unsigned int SavingsAccount::getWithdrawals() const
{
	return withdrawals;
}

const double SavingsAccount::getInterest() const
{
	return interest;
}

const bool SavingsAccount::setInterest(const double amount)
{
	return (interest=amount);	
}
