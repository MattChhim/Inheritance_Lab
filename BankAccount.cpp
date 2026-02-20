#include "BankAccount.h"

void BankAccount::withdraw(double amount) {
	if (amount > 0 && amount <= *balance) {
		*balance -= amount;
	}
}