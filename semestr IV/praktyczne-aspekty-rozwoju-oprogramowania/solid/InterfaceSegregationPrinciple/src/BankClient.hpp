#pragma once
#include "BankAccount.hpp"
#include <iostream>

class BankClient
{
public:
    BankClient(BankAccount& account)
        :account(account)
    {}

    void use()
    {
        std::cout << "Dzień dobry kiliencie! Saldo Twojego konta wynosi: " << account.getBalance() << " cebulionów!\n";
        account.incrementBalance(100);
    }
private:
    BankAccount& account;
};
