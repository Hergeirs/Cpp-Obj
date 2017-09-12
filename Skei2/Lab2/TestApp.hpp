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
    void deposit();
    void withdraw();
    void viewAccounts() const;
    void viewTotalAssets() const;
    void removeAccount();
    //quit
    
};


#endif