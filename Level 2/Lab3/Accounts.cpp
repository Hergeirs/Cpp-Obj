#include "Accounts.hpp"

/*

Accounts::Accounts()
:maxAccounts(3)
{

}

const bool Accounts::full() const
{
    return (transAccounts.size()+savingsAccounts.size()+longTermAccounts.size())==3;
}

const bool Accounts::empty() const
{
    return transAccounts.empty() && savingsAccounts.empty() && longTermAccounts.empty();
}



const bool Accounts::push_back(TransactionAccount a)
{
    if(!full())
    {
        transAccounts.push_back(std::make_unique<TransactionAccount>(a));
        return true;
    }
    return false;
}

const bool Accounts::push_back(SavingsAccount a)
{
    if(!full())
    {
        savingsAccounts.push_back(std::make_unique<SavingsAccount>(a));
        return true;
    }
    return false;
}



const bool Accounts::push_back(LongTermSavingsAccount a)
{
    if(!full())
    {
        longTermAccounts.push_back(std::make_unique<LongTermSavingsAccount>(a));
        return true;
    }
    return false;
}

*/