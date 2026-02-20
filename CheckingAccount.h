#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"


class CheckingAccount : public BankAccount {
public:
	// Constructor for balance and transaction fee
	CheckingAccount(std::string id, std::string name, double initalBalance, double fee);

	// Override the withdraw function to include transaction fee
	void withdraw(double amount) override;


private:
	double transactionFee;




};




#endif
