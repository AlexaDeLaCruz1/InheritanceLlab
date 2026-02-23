/*
Author: Alexa De La Cruz
Date: 2/13/2026
Purpose: Enhancing the Bank Account Management System
*/

#include "BankAccount.h"
#include <vector>
#include <memory>

int main() {
    // Vector of base class pointers
    std::vector<std::unique_ptr<BankAccount>> accounts;

    // Add different types of accounts
    accounts.push_back(std::make_unique<CheckingAccount>(101, "Alice", 500.0, 1.50));
    accounts.push_back(std::make_unique<SavingsAccount>(202, "Bob", 1000.0, 0.05));

    int choice;
    do {
        std::cout << "\n--- Account Management ---\n";
        for (size_t i = 0; i < accounts.size(); ++i) {
            std::cout << i << ". " << accounts[i]->getHolder() 
                      << " (Balance: $" << accounts[i]->getBalance() << ")\n";
        }
        std::cout << "Select account index (or -1 to exit): ";
        std::cin >> choice;

        if (choice >= 0 && (size_t)choice < accounts.size()) {
            std::cout << "1. Withdraw\n2. Add Interest (Savings Only)\nChoice: ";
            int action;
            std::cin >> action;

            if (action == 1) {
                double amt;
                std::cout << "Amount: ";
                std::cin >> amt;
                // POLYMORPHISM: calls the correct version of withdraw
                accounts[choice]->withdraw(amt);
            } 
            else if (action == 2) {
                // Downcasting to access Savings-specific function
                SavingsAccount* sa = dynamic_cast<SavingsAccount*>(accounts[choice].get());
                if (sa) {
                    sa->calculateInterest();
                } else {
                    std::cout << "This is not a savings account!\n";
                }
            }
        }
    } while (choice != -1);

    return 0;
}
