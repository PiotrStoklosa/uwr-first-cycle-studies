#pragma once

class BankAccount
{
public:
    bool decrementBalance(unsigned int decrementBy)
    {
        if (decrementBy > balance)
            return false;
        balance -= decrementBy;
        return true;
    }

    void incrementBalance(unsigned int incrementBy)
    {
        balance += incrementBy;
    }

    int getBalance() const
    {
        return balance;
    }

private:
    int balance{};
};
