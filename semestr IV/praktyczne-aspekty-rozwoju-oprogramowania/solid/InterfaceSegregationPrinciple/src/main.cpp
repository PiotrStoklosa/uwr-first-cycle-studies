#include <iostream>

#include "BankAccount.hpp"
#include "OutgoingPayment.hpp"
#include "IncomingPayment.hpp"
#include "BankClient.hpp"

int main()
{
    BankAccount account;
    BankClient client(account);

    applyIncomingPayment(account, 11);
    applyOutgoingPayment(account, 10);


    client.use();
    client.use();
    client.use();
    client.use();

    return 0;
}
