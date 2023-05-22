//Piotr Stoklosa zadanie 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<pair<int, string>> rzym = {{1000, "M"},{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string bin2rom(int x)
{
    if (x<1 || x>3999)
    {
        string wyjatek="Liczba poza zakresem!";
        throw wyjatek;
    }
    string rom;
    for (unsigned int i=0; i<rzym.size(); i++)
    {
        while (x/rzym[i].first)
        {
            rom+=rzym[i].second;
            x-=rzym[i].first;
        }
    }
    return rom;
}

int main(int argc, char* argv[])
{
    if (argc<2)
        clog<<"Nie podano argumentow\n";

    int number;

    for (int i=1; i<argc; i++)
    {
        try
        {
            number=stoi(argv[i]);
        }

        catch (invalid_argument arg)
        {
            clog<<"Nie udalo sie przekonwertowac liczby!\n";
            continue;
        }

        try
        {
            cout<<bin2rom(number)<<'\n';
        }

        catch (string wyjatek)
        {
            clog<<wyjatek<<'\n';
        }

    }

    return 0;
}
