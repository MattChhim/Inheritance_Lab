#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

class BankAccount {
public:
	// Constructor for BankAccount
	BankAccount() {
		accountNumber = "000000";
		accountHolderName = "Default Name";
		balance = new double(0.0); // Dynamically allocated memory for balance
	}

	BankAccount(std::string id, std::string name, double initialBalance) {
		accountNumber = id;
		accountHolderName = name;
		balance = new double(initialBalance);
	}

	// Rule of Three: Destructor, Copy Constructor, and Copy Assignment Operator

	// Destructor to free allocated memory
	virtual ~BankAccount() {
		delete balance;
	}

	// Copy Constructor for deep copy
	BankAccount(const BankAccount& other) {
		accountNumber = other.accountNumber;
		accountHolderName = other.accountHolderName;

		// Allocate new memory for balance and copy from other object

		balance = new double(*other.balance); // Deep copy of balance
	}

	// Copy Assignment Operator for self assignment and deep copy
	BankAccount& operator=(const BankAccount& other) {
		if (this != &other) {
			accountNumber = other.accountNumber;
			accountHolderName = other.accountHolderName;

			// Open new memory for balance and copy
			delete balance;
			balance = new double(*other.balance);
		}
		return *this;

	}

	// Arithmetic Assignment Operators

	// Arithmetic Assignment Operator for Deposit
	BankAccount& operator+=(double amount) {
		if (amount > 0) {
			*balance += amount; // Adds amount to current balance
		}
		return *this; // Returns reference to the current object
	}

	// Arithmetic Assignment Operator for Withdrawal
	BankAccount& operator-=(double amount) {
		if (amount > 0) {
			if (amount <= *balance) {
				*balance -= amount; // Subtracts amount from balance
			}
			else {
				std::cout << "\nInsufficient funds. Withdrawal amount exceeds balance amount.\n" << std::endl;
			}
		}
		return *this; // Returns reference to the current object
	}

	// Comparison Operators

	// Equality operator: If account numbers are the same, return true
	bool operator==(const BankAccount& other) const {
		return this->accountNumber == other.accountNumber;
	}

	// Less Than operator: If current balance is less than other balance, return true
	bool operator<(const BankAccount& other) const {
		return *this->balance < *other.balance;
	}

	// Greater Than operator: If current balance is greater than other balance, return true
	bool operator>(const BankAccount& other) const {
		return *this->balance > *other.balance;
	}

	// Static Utility Functions

	// Static Function to print account details
	static void printAccount(const BankAccount& account) {
		std::cout << "---------------" << std::endl;
		std::cout << "Account Number: " << account.accountNumber << std::endl;
		std::cout << "Account Holder: " << account.accountHolderName << std::endl;
		std::cout << "Balance: $" << account.getBalance() << std::endl;
	}

	// Static Function to create a BankAccount object from user input
	static BankAccount createAccountFromInput() {
		std::string id, name;
		double initialBalance;

		std::cout << "\nCreating a new bank account.\n" << std::endl;
		std::cout << "Enter Account Number: ";
		std::cin >> id;
		std::cin.ignore(); // Clear newline
		std::cout << "\nEnter Account Holder name: ";
		std::getline(std::cin, name); // Use getline for spaces in names
		std::cout << "\nEnter your starting balance: ";
		while (!(std::cin >> initialBalance) || initialBalance < 0) {
			std::cout << "\nInvalid input. Please enter a non-negative number for your starting balance: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		return BankAccount(id, name, initialBalance); // Return new BankAccount object
	}

	// Accessor methods or getters
	std::string getAccountNumber() const {
		return accountNumber;
	}

	std::string getaccountHolderName() const {
		return accountHolderName;
	}

	double getBalance() const {
		return *balance;
	}

	void setAccountHolderName(std::string name) {
		accountHolderName = name;
	}


	// Virtual withdraw method to be overridden by derived classes
	virtual void withdraw(double amount);


private:
	// Private members
	std::string accountNumber;
	std::string accountHolderName;
	double* balance;
};

#endif