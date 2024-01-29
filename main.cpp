/**
 * @file main.cpp
 * @author Eduard Jaha (jaha.eduard@gmail.com)
 * @brief This tool buys and sells two types of cryptos.
 * @version 0.1
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>

#include "include/TradeCrypto.hpp"

int main () {
    Account user;

    int amount;
    int choice;
    bool check;

    while (1) {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Press 1 if want to have your Account Info "
             << std::endl;
        std::cout << "Press 2 if want to Deposit your money "
             << std::endl;
        std::cout << "Press 3 if want to withdraw your money "
             << std::endl;
        std::cout << "Press 4 if want to know your Buy Crypto "
             << std::endl;
        std::cout << "Press 5 if want to know your Sell Crypto "
             << std::endl;
        std::cout << "Press 6 if want to know your history "
             << std::endl;
        std::cout << "Else press any invalid key for exit \n"
             << std::endl;
        std::cout << "------------------------------------------" << std::endl;

        std::cin >> choice;
        int ans;

        switch (choice)
        {
        case 1:
            user.AccountInformation();
            break;
        case 2:
            std::cout << "Enter the amount to deposit: " << std::endl;
            std::cin >> amount;
            ans = user.Deposit(amount);
            if (ans) {
                std::cout << "Money deposited successfully." << std::endl;
            } else {
                std::cout << "Something went wrong!!" << std::endl;
            }
            break;
        case 3:
            std::cout << "Enter amount to withdrawn: " << std::endl;
            std::cin >> amount;
            user.Withdraw(amount);
            if (ans) {
                std::cout << "Amount withdrawn successfully." << std::endl;
            } else {
                std::cout << "Not Enough Balance!" << std::endl;
            }
            break;
        case 4:
            ans = user.BuyCrypto();
            if (ans) {
                std::cout << "Successful Transaction." << std::endl;
            } else {
                std::cout << "Not enough money to buy!" << std::endl;
            }
            break;
        case 5:
            ans = user.SellCrypto();
            if (ans) {
                std::cout << "Successful Transaction." << std::endl;
            } else {
                std::cout << "Not enough crypto to sell!" << std::endl;
            }
            break;
        case 6:
            user.TransactionHistory();
            break;
        default:
            exit(0);
            break;
        }
    }
}
