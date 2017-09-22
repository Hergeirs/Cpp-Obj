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
        virtual const bool setInterest(const double amount) override; //only within class
        virtual const unsigned int getWithdrawals() const override;
        const unsigned int maxWithdrawals;
        static double interest;
        unsigned int withdrawals;
        SavingsAccount(const unsigned int accountNo, const double balance,const AccountType accountType, const unsigned int pWithdrawals, const unsigned int pMaxWithdrawals);
};


#endif