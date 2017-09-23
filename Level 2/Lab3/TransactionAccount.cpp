#include "TransactionAccount.hpp"

TransactionAccount::TransactionAccount(const unsigned int accountNo,const double amount,const double pCredit)
:Account(accountNo,amount,TRANSACTION),credit(pCredit)
{
	//
}

const bool TransactionAccount::withdraw(const double amount)
{
	return balance+credit < amount ? false : (balance-=amount); 
}

const bool TransactionAccount::setCredit(const double newCredit)
{
	return balance+newCredit < 0 ? false : (credit=newCredit);
}

const double TransactionAccount::getUsableBalance() const
{
	return balance+credit;
}

const double TransactionAccount::getCredit() const
{
	return credit;
}