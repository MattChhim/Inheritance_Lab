#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
	// Constructor for initiallizing the balance and interest rate
	SavingsAccount(std::string id, std::string name, double initialBalance, double rate);

	// New method to calculate interest and add to balance
	void calculateInterest();

private:
	double interestRate;




};





#endif
