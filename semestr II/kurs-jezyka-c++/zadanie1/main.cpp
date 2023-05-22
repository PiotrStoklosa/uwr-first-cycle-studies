//Piotr Stoklosa zad 1
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int64_t> factorisation(int64_t number)
{
    vector<int64_t> v;
    if (number>=-1 && number<=1)
    {
        v.push_back(number);
        return v;
    }
    if (number<0 && number>=-9223372036854775807)
    {
        v.push_back(-1);
        number*=-1;
    }
    else if (number<0)
    {
        v.push_back(-1);
        v.push_back(2);
        number/=2;
        number/=-1;
    }
    while(number%2==0)
    {
        number/=2;
        v.push_back(2);
    }
    for (int64_t i=3; i<=floor(sqrt(number)); i+=2)
    {
        while (number%i==0)
        {
            v.push_back(i);
            number/=i;
        }
    }
    if (number>1)
        v.push_back(number);
    return v;
}
bool prime(int64_t number)
{
    if (number<2)
        return false;
    if (number%2==0)
        return false;
    for (int i=3; i*i<=number; i+=2)
        if (number%i==0)
            return false;
    return true;
}
int64_t convertion(string word)
{
    int64_t sign=1;
    int64_t number=0;
    int64_t mult=1;
    if(word[0]=='-')
    {
        word.erase(0,1);
        sign=-1;
    }
    if (word.length()==0)
    {
        invalid_argument arg("Pusta liczba!");
        throw arg;
    }
    if (word.length()>19)
    {
        invalid_argument arg("Liczba wykracza poza zakres!");
        throw arg;
    }
    for (int i=word.length()-1; i>=0; i--)
    {
        if (word[i]<'0' || word[i]>'9')
        {
            invalid_argument arg("Nie podano liczby!");
            throw arg;
        }
        number+=(int(word[i])-48)*mult*sign;
        mult*=10;
    }
    if ((sign>0 && number<0) || (sign<0 && number>0))
    {
        invalid_argument arg("Liczba wykracza poza zakres!");
        throw arg;
    }
    return number;
}
void print(vector<int64_t> v1, int64_t number)
{
    cout<<number<<"=";
    bool mul=false;
    for (int64_t i : v1)
        {
            if (mul)
                cout<<"*";
            cout<<i;
            mul=true;
        }

    cout<<'\n';
}
int main(int argc, char* argv[])
{
    if (argc<2)
        cerr<<"Za malo argumentow, prosze podac argumenty do faktoryzacji!\n";
    int64_t word;
    for (int i=1; i<argc; i++)
    {
        try
        {
            word=convertion(argv[i]);
        }
        catch(invalid_argument arg)
        {
            cerr<<arg.what()<<'\n';
            continue;
        }
        vector<int64_t> num=factorisation(word);
        print(num, word);
    }
    return 0;
}
