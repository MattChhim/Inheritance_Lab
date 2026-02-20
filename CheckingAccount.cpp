#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string id, std::string name, double initialBalance, double fee) : BankAccount(id, name, initialBalance), transactionFee(fee) {

}

void CheckingAccount::withdraw(double amount) {
	double totalWithdrawal = amount + transactionFee;

	// Call base class withdraw to update the balance
	BankAccount::withdraw(totalWithdrawal);



}