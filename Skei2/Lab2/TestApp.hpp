#ifndef TESTAPPH
#define TESTAPPH

#include "Bank.hpp"
#include "Menu.hpp"

class TestApp
{
public:
    TestApp();
    ~TestApp();
    void run();
private:
    
    Bank bank;

//menu-implementation
    Menu menu;
    const bool doMenuChoice(const int choice);

//menu-options    
    void createCustomer();
    void manageCustomer();
    void changeCustomerName();
    void createAccount();
    void changeAccountCredit();
    void deposit();
    void withdraw();
    void viewAccounts() const;
    void viewAccount() const;
    void viewTotalAssets() const;
    void removeAccount();
    //quit

// print account functions
    const unsigned int getAccountNo() const;
    void printAccountInfo(const unsigned int accountNo) const;
    void printAccountInfo(const AccountInfo info, const bool pause=false, const bool clear=true) const;
};


#endif