#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : accountNumber(0), accountHolder("N/A"), balance(0.0) {}

BankAccount::BankAccount(int accNum, std::string holder, double initialBalance) 
    : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolder = other.accountHolder;
    balance = other.balance;
}

// to prevent self-assignment
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) { // to prevent self-assignment
        accountNumber = other.accountNumber;
        accountHolder = other.accountHolder;
        balance = other.balance;
    }
    return *this;
}

BankAccount::~BankAccount() {



BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) balance += amount;
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds or invalid amount.\n";
    }
    return *this;
}  // :]

bool BankAccount::operator==(const BankAccount& other) const {
    return this->accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return this->balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return this->balance > other.balance;
}

// double check!!!! 
void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "\n--- Account Details ---" << std::endl;
    std::cout << "Account #: " << account.accountNumber << std::endl;
    std::cout << "Holder:    " << account.accountHolder << std::endl;
    std::cout << "Balance:   $" << account.balance << std::endl;
}

BankAccount BankAccount::createAccountFromInput() {
    int id;
    std::string name;
    double bal;

    std::cout << "Enter Account Number: ";
    std::cin >> id;
    std::cin.ignore(); // Clear newline
    std::cout << "Enter Holder Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: ";
    std::cin >> bal;

    return BankAccount(id, name, bal);
}
