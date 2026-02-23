/*
Author: Alexa De La Cruz
Date: 2/13/2026
Purpose: Enhancing the Bank Account Management System
*/

#include "BankAccount.h"
#include <iostream>
#include <vector>

int main() {
    BankAccount myAccount = BankAccount::createAccountFromInput();
    int choice;

    do {
        std::cout << "\n1. Deposit (+=)\n2. Withdraw (-=)\n3. View Details (Static Print)\n4. Compare with another\n5. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            double amt;
            std::cout << "Enter deposit amount: ";
            std::cin >> amt;
            myAccount += amt; // Using overloaded operator
        } else if (choice == 2) {
            double amt;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amt;
            myAccount -= amt; // Using overloaded operator
        } else if (choice == 3) {
            BankAccount::printAccount(myAccount); // Using static function
        } else if (choice == 4) {
            std::cout << "Create a second account for comparison:\n";
            BankAccount other = BankAccount::createAccountFromInput();
            
            if (myAccount == other) std::cout << "Same account numbers!\n";
            if (myAccount > other)  std::cout << "Primary account has a higher balance.\n";
            if (myAccount < other)  std::cout << "Primary account has a lower balance.\n";
        }
    } while (choice != 5);

    return 0;
}
