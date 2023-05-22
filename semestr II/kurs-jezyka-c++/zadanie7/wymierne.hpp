#include <iostream>
#include <climits>
#ifndef WYMIERNEHPP

using namespace std;


namespace obliczenia{

    class Wyjatek_wymierny : exception{
    public:
        const char *what () const noexcept override;
    };

    class Dzielenie_przez_0 : public Wyjatek_wymierny{
        public:
            const char *what () const noexcept override;
    };

    class Przekroczenie_zakresu : public Wyjatek_wymierny{
        public:
        const char *what () const noexcept override;
    };

    long long int nwd(long long int, long long int);
    class Wymierna{
    private:
        int licz,mian;

    public:
        int get_licz();
        int get_mian();
        Wymierna(int,int);
        Wymierna(int);
        friend ostream& operator<< (ostream &, Wymierna &);
        friend Wymierna operator + (Wymierna, Wymierna);
        friend Wymierna operator - (Wymierna, Wymierna);
        friend Wymierna operator * (Wymierna, Wymierna);
        friend Wymierna operator / (Wymierna, Wymierna);
        friend Wymierna operator - (Wymierna);
        friend Wymierna operator ! (Wymierna);
        operator double();
        operator int();
    };
}
#endif
