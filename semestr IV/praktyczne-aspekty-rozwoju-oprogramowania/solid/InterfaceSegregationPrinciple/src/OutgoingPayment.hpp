#pragma once

#include <iostream>
#include "BankAccount.hpp"

void applyOutgoingPayment(BankAccount& accountToDecrement, unsigned int amount)
{
    std::cout << "Przelew wychodzacy o wartości: " << amount << " cebulionów ";
    if (accountToDecrement.decrementBalance(amount))
        std::cout << "został zrealizowany\n";
    else
        std::cout << "nie został zrealizowany. Brak wystarczających środków na koncie.\n";

}
