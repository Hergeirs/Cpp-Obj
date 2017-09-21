#ifndef TRANSACTIONACCOUNTH
#define TRANSACTIONACCOUNTH

#include "Account.hpp"

class TransactionAccount : public Account
{ 
	public:
		TransactionAccount(const unsigned int accountNo,const double amount=0,const double pCredit=0);

		virtual const bool withdraw(const double amount) override;
		virtual const bool setCredit(const double newCredit) override;
		virtual const double getUsableBalance() const override;
	private:
		double credit;
};

#endif