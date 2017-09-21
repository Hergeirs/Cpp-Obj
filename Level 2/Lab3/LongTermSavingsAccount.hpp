#ifndef LONGTERMSAVINGSACCOUNT
#define LONGTERMSAVINGSACCOUNT

#include "SavingsAccount.hpp"

class LongTermSavingsAccount : public SavingsAccount
{
	public:
	LongTermSavingsAccount(const unsigned int accountNo,const double amount=0, const unsigned int pWithdrawals=0);
};

#endif