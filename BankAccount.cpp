// Matthew Chhim, 2/6/2026, The purpose of this program is to create a BankAccount class and use the rule of three, overloaded operators, and static utility functions, Operator Overload Lab 
#include <iostream>
#include <vector>
#include <string>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

void BankAccount::withdraw(double amount) {
	if (amount > 0 && amount <= *balance) {
		*balance -= amount;
	}
}

int main() {
	std::vector<BankAccount*> accounts;

	accounts.push_back(new CheckingAccount("C1", "Tommy", 1000.0, 500.0));

	accounts.push_back(new SavingsAccount("S1", "Sarah", 3000.0, 0.75));

	int option;

	do {

	std::cout << "--- Bank Account Management System ---\n" << std::endl;
	std::cout << "1. Add new bank account: \n" << std::endl;
	std::cout << "2. Deposit Funds: \n" << std::endl;
	std::cout << "3. Withdraw Funds: \n" << std::endl;
	std::cout << "4. Display Accounts: \n" << std::endl;
	std::cout << "5. Quit. \n" << std::endl;
	std::cout << "What would you like to do next? \n" << std::endl;
	std::cin >> option;

	switch (option) {

	case 1: {

		int type;
		std::string id, name;
		double balance, extra; // extra for either overdraft or interest for checking and savings account respectively

		std::cout << "1. Checking Account\n2. Savings Account\nEnter type: ";
		std::cin >> type;

		std::cout << "Enter ID: "; std::cin >> id;
		std::cin.ignore();

		std::cout << "Enter Name: "; std::getline(std::cin, name);
		std::cout << "Enter Balance: "; std::cin >> balance;

		if (type == 1) {
			std::cout << "Enter Transaction Fee: "; std::cin >> extra;
			accounts.push_back(new CheckingAccount(id, name, balance, extra));
		}
		else {
			std::cout << "Enter Interest Rate (e.g. 0.02): "; std::cin >> extra;
			accounts.push_back(new SavingsAccount(id, name, balance, extra));
		}


		std::cout << "\nAccount created successfully.\n" << std::endl;
		break;
	}

	case 2: {
		// Deposit Funds
		std::string depositId;
		double depositAmount;
		bool foundDeposit = false;

		std::cout << "\n--- Deposit Funds ---\n" << std::endl;

		// Checking if there are any accounts to deposit into
		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		std::cout << "Enter Account Number to deposit into: ";
		std::cin >> depositId;

		// Search for account within vector
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAccountNumber() == depositId) {


				foundDeposit = true;

				// Input validation for deposit amount
				std::cout << "Enter amount to deposit: ";
				while (!(std::cin >> depositAmount) || depositAmount <= 0) {
					std::cout << "\nInvalid input. Please enter a positive number for the deposit amount: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}

				*accounts[i] += depositAmount; // Using overloaded operator to deposit amount
				std::cout << "\nDeposit successful: $" << depositAmount << " has been added to your account" << std::endl;
				break;
			}

		}

		if (!foundDeposit) {
			std::cout << "\nAccount not found. Check the account number again.\n" << std::endl;
		}

		break;
	}

	case 3: {
		std::string withdrawId;
		double withdrawAmount;
		bool foundWithdraw = false;

		std::cout << "\n--- Withdraw Funds ---\n" << std::endl;

		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		std::cout << "Enter Account Number to withdraw from: ";
		std::cin >> withdrawId;

		// Search for account within vector
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAccountNumber() == withdrawId) {
				foundWithdraw = true;

				// Input validation for withdrawal amount
				std::cout << "Enter amount to withdraw: ";
				while (!(std::cin >> withdrawAmount) || withdrawAmount <= 0) {
					std::cout << "\nInvalid input. Please enter a positive number for the withdraw amount: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}

				accounts[i]->withdraw(withdrawAmount); // Using overloaded operator to withdraw amount
				std::cout << "\nWithdrawal successful: $" << withdrawAmount << " has been withdrawn from your account" << std::endl;
				break;
			}
		}
		if (!foundWithdraw) {
			std::cout << "\nAccount not found. Check the account number again.\n" << std::endl;
		}

		break;
	}

	case 4: {
		std::cout << "\n--- Displaying All Accounts ---\n" << std::endl;

		if (accounts.empty()) {
			std::cout << "\nNo accounts available." << std::endl;
			break;
		}

		// Loop through accounts and display info
		std::cout << "\n ---Displaying All Accounts--- \n" << std::endl;
		if (accounts.empty()) {
			std::cout << "\nNo account available." << std::endl;
			break;
		}

		for (const auto& accountPtr : accounts) {
			BankAccount::printAccount(*accountPtr); // Using static function to print accounts
		}
		std::cout << "---------------\n" << std::endl;
		break;
	}

	case 5: {
		std::cout << "\nExiting the program. Goodbye.\n" << std::endl;
		break;

	default:
		std::cout << "\nInvalid option. Please try again.\n" << std::endl;
		break;
	}
	}

	} while (option != 5);
	
	for (BankAccount* acc : accounts) {
		delete acc;
	}
	accounts.clear();

	return 0;
}