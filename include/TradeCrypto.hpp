#ifndef TRADE_CRYPTO_H
#define TRADE_CRYPTO_H

#include <vector>
#include <utility>
#include <string>

class Account {
    int bitcoin;
    int ether;
    int balance;
    int deposit;
    int withdraw;
    int total_equity = 100;
    int predict;
    int bitcoin_value;
    int ether_value;
    int crypto_invest;
    int crypto_return;
    std::vector<std::pair<std::string, int>> transactions;

  public:
    /**
     * @brief Get account details 
     */
    void AccountInformation();
    /**
     * @brief Deposit the amount of money 
     */
    bool Deposit(int money);
    /**
     * @brief Withdraw the amount of money 
     */
    bool Withdraw(int money);
    /**
     * @brief Buy Crypto 
     * 
     */
    bool BuyCrypto();
    /**
     * @brief Sell Crypto
     * 
     */
    bool SellCrypto();
    /**
     * @brief Check the transaction history
     * 
     */
    void TransactionHistory();

    Account () {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;

        balance = 50000;
        ether = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        ether_value = 2000;
        bitcoin_value = 30000;
    }
};

#endif // TRADE_CRYPTO_H
