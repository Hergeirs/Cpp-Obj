#include "LongTermSavingsAccount.hpp"

double SavingsAccount::interest;

LongTermSavingsAccount::LongTermSavingsAccount(const unsigned int accountNo, const double amount, const unsigned int pWithdrawals)
:SavingsAccount(accountNo,amount,LONGTERMSAVINGS,pWithdrawals,1)
{    
    //
}
// Function to make the interest in all practical senses 2% higher than savings account.
const double LongTermSavingsAccount::getInterest() const
{
    return interest+0.02;
}
