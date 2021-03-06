#ifndef SAVINGSACCOUNTH
#define SAVINGSACCOUNTH

#include "Account.hpp"

class SavingsAccount : public Account
{
    public:
        SavingsAccount(const unsigned int accountNo, const double balance=0, const unsigned int pWithdrawals=0);
        virtual const bool withdraw(const double amount) override;
        virtual const double getInterest() const override;
    
    protected:
        virtual const unsigned int getWithdrawals() const override;
        static double interest;        
        const unsigned int maxWithdrawals;
        unsigned int withdrawals;
        SavingsAccount(const unsigned int accountNo, const double balance,const AccountType accountType, const unsigned int pWithdrawals, const unsigned int pMaxWithdrawals);
};


#endif