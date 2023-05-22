#include "wymierne.hpp"
#include <math.h>

namespace obliczenia{

    long long int nwd(long long int licznik, long long int mianownik)
    {
        long long int temp;

        while(mianownik)
        {
            temp = licznik % mianownik;
            licznik = mianownik;
            mianownik = temp;
        }

        return licznik;
    }

    Wymierna::Wymierna(int licznik, int mianownik)
    {
        try{
            if (mianownik == 0)
                throw Dzielenie_przez_0();
        }

        catch (const Dzielenie_przez_0& blad){
            cerr << blad.what()<<'\n';
        }

        bool sign = 0;

        if (licznik<0)
        {
            sign = !sign;
            licznik*=-1;
        }
        if (mianownik<0)
        {
            sign = !sign;
            mianownik*=-1;
        }

        int dzielnik = nwd(licznik, mianownik);
        licz = licznik/dzielnik;
        mian = mianownik/dzielnik;

        if (sign)
            licz*=-1;
    }

    int Wymierna::get_licz()
    {
        return licz;
    }

    int Wymierna::get_mian()
    {
        return mian;
    }

    Wymierna::Wymierna(int licznik)
    {
        licz = licznik;
        mian = 1;
    }

    const char *Wyjatek_wymierny::what() const noexcept
    {
        return "Zgloszono wyjatek!";
    }

    const char *Dzielenie_przez_0::what() const noexcept
    {
        return "Podzielono przez 0!";
    }

    const char *Przekroczenie_zakresu::what() const noexcept
    {
        return "Przekroczono zakres!";
    }

    Wymierna operator + (Wymierna w1, Wymierna w2)
    {
        long long int temp_licznik,temp_mianownik, dzielnik, licznik1, mianownik1, licznik2, mianownik2;

        try{
            licznik1 = w1.get_licz();
            licznik2 = w2.get_licz();
            mianownik1 = w1.get_mian();
            mianownik2 = w2.get_mian();

            temp_licznik = licznik1 * mianownik2 + licznik2 * mianownik1;
            temp_mianownik = mianownik1 * mianownik2;

            bool sign = 0;
            if (temp_licznik<0)
            {
                sign = 1;
                temp_licznik*=-1;
            }
            dzielnik = nwd(temp_licznik, temp_mianownik);
            if (sign)
                temp_licznik*=-1;

            temp_licznik/=dzielnik;
            temp_mianownik/=dzielnik;

            if (temp_licznik > INT_MAX || temp_licznik < INT_MIN || temp_mianownik > INT_MAX)
                throw Przekroczenie_zakresu();
        }

        catch(const Przekroczenie_zakresu &blad){
            cerr<<blad.what() << '\n';
        }

        int licznik = (int) temp_licznik;
        int mianownik = (int) temp_mianownik;
        return {licznik, mianownik};
    }

    Wymierna operator - (Wymierna w1, Wymierna w2)
    {
        return w1 + (-w2);
    }

    Wymierna operator * (Wymierna w1, Wymierna w2)
    {
        long long int temp_licznik, temp_mianownik, dzielnik, licznik1, mianownik1, licznik2, mianownik2;

        try{

            licznik1 = w1.get_licz();
            licznik2 = w2.get_licz();
            mianownik1 = w1.get_mian();
            mianownik2 = w2.get_mian();

            temp_licznik = licznik1 * licznik2;
            temp_mianownik = mianownik1 * mianownik2;

            bool sign = 0;
            if (temp_licznik<0)
            {
            sign = 1;
                    temp_licznik*=-1;
            }

            dzielnik = nwd(temp_licznik, temp_mianownik);

            if (sign)
                    temp_licznik*=-1;

            temp_licznik/=dzielnik;
            temp_mianownik/=dzielnik;

            if (temp_licznik > INT_MAX || temp_licznik < INT_MIN || temp_mianownik > INT_MAX || temp_mianownik < INT_MIN)
                throw Przekroczenie_zakresu();
        }

        catch(const Przekroczenie_zakresu &blad){
            cerr<<blad.what() << '\n';
        }

        int licznik = (int) temp_licznik;
        int mianownik = (int) temp_mianownik;

        return {licznik, mianownik};

    }

    Wymierna operator / (Wymierna w1, Wymierna w2)
    {
        return w1 * !w2;
    }

    Wymierna operator - (Wymierna w)
    {
        try{
            if (w.get_licz() == INT_MIN)
                throw Przekroczenie_zakresu();
        }
        catch(const Przekroczenie_zakresu &blad){
            cerr<<blad.what() << '\n';
        }
        w.licz *= -1;
        return w;
    }

    Wymierna operator ! (Wymierna w)
    {
        return {w.get_mian(),w.get_licz()};
    }

    Wymierna::operator double()
    {
        return (double) licz/mian;
    }

    Wymierna::operator int()
    {
        return round((double) *this);
    }

    ostream& operator << (ostream &output, Wymierna &x)
    {
        output << to_string((double)x);
        return output;
    }
}
