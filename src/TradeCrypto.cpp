/**
 * @file TradeCrypto.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief Functions from class Account, that are implemented to be used in main
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/TradeCrypto.hpp"

#include <iostream>

void Account::AccountInformation(){
    std::cout << "-Account Details-" << std::endl;
    std::cout << "Bank Balance: " << balance << std::endl;
    std::cout << "Etherium: " << ether << std::endl;
    std::cout << "Bitcoin: " << bitcoin << std::endl; 
}

bool Account::Deposit(int money){
    deposit += money;
    balance += money;
    transactions.push_back({"Deposit: ", money});
    return true;
}

bool Account::Withdraw(int money){
    if (money > balance) {
        return false;
    }
    withdraw += money;
    balance -= money;
    transactions.push_back({"Withdraw: ", money});
    return true;
}

bool Account::BuyCrypto(){
    int option;
    std::cout << "Please select which crypto you would like to buy \n"
                 "(1) Ether\n"
                 "(2) Bitcoin" << std::endl;
    std::cin >> option;

    if (total_equity != 0) {
        if (option == 1) {
            ether += 1;
            balance -= ether_value;
            crypto_invest += ether_value;
            std::cout << "Purchase successful: Etherium bought.\n";
            return true;
        } else if (option == 2) {
            bitcoin += 1;
            balance -= bitcoin_value;
            crypto_invest += bitcoin_value;
            std::cout << "Purchase successful: Bitcoin bought.\n";
            return true;
        } else {
            std::cout << "Invalid option. Purchase failed.\n";
            return false;
        }
    }
    else {
        std::cout << "Insufficient equity. Purchase failed.\n";
        return false;
    }
}

bool Account::SellCrypto(){
    int option;

    std::cout << "Please select which crypto you would like to sell \n"
                 "(1) Ether\n"
                 "(2) Bitcoin" << std::endl; 
    std::cin >> option;

    if (option == 2) {
        if (bitcoin == 0) {
            return false;
        }
        crypto_return += bitcoin_value;
        balance += bitcoin_value;
        transactions.push_back({"Bitcoin Sold: ", bitcoin_value});
        bitcoin -= 1;
    } else {
        if (ether == 0) {
            return false;
        }
        crypto_return += ether_value;
        balance += ether_value;
        transactions.push_back({"Etherium Sold: ", ether_value});
        ether -= 1;
    }

    return true;
}

void Account::TransactionHistory() {
    std::cout << "Display all transactions" << std::endl;
    for (auto it : transactions) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    char temp;
    std::cout << "Do you want to clear all the transactions?" << std::endl;
    std::cin >> temp;

    int number = transactions.size();

    if (temp == 'Y') {
        transactions.clear();
        std::cout << "Total transactions cleared: " << number << std::endl;
    } else {
        std::cout << "Total transactions: " << number << std::endl;
    }
}
