#include "LongTermSavingsAccount.hpp"

double SavingsAccount::interest;

LongTermSavingsAccount::LongTermSavingsAccount(const unsigned int accountNo, const double amount, const unsigned int pWithdrawals)
:SavingsAccount(accountNo,amount,LONGTERMSAVINGS,pWithdrawals,1)
{
    interest+=0.02; // interest should be 2% over SavingsAccount
}
