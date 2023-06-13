#include <iostream>

using namespace std;

int main()
{
    long long int poczatek;
    long long int koniec;

    scanf("%lld %lld", &poczatek, &koniec);

    if (poczatek % 2021)
        poczatek =  poczatek + (2021 - (poczatek % 2021));

    if (poczatek <= koniec){

        printf("%lld", poczatek);
        poczatek += 2021;

    }

    for (long long int i = poczatek; i <= koniec; i += 2021)
        printf(" %lld", i);

    return 0;
}
