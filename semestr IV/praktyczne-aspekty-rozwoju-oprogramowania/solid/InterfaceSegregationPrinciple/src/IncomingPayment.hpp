#pragma once

#include <iostream>
#include "BankAccount.hpp"

void applyIncomingPayment(BankAccount& accountToIncrement, unsigned int amount)
{
    std::cout << "Przelew przychodzący o wartości: " << amount << " cebulionów!\n";
    accountToIncrement.incrementBalance(amount);
}
