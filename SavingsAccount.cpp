#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string id, std::string name, double initialBalance, double rate) : BankAccount(id, name, initialBalance), interestRate(rate) {
}

void SavingsAccount::calculateInterest() {
	double currentBalance = getBalance();

	double interestAmount = currentBalance * interestRate;

	*this += interestAmount; // Add the interest to the current balance
}