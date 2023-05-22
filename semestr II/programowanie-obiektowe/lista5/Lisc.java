//Piotr Stoklosa zad 2
import java.io.*;
import java.util.Hashtable;

class Dodaj extends Wyrazenie
{
    	Wyrazenie prawe;
    	Wyrazenie lewe;

    	public Dodaj (Wyrazenie pierwsze, Wyrazenie drugie)
    	{
        	lewe = pierwsze;
        	prawe = drugie;
		wartosc = lewe.wartosc + prawe.wartosc;
		wyrazenie = "(" + lewe.wyrazenie + " + " + prawe.wyrazenie + ")";
    	}
}
class Odejmij extends Wyrazenie
{
    	Wyrazenie prawe;
    	Wyrazenie lewe;

    	public Odejmij (Wyrazenie pierwsze, Wyrazenie drugie)
    	{
        	lewe = pierwsze;
        	prawe = drugie;
		wartosc = lewe.wartosc - prawe.wartosc;
		wyrazenie = "(" + lewe.wyrazenie + " - " + prawe.wyrazenie + ")";
    	}
}
class Pomnoz extends Wyrazenie
{
    	Wyrazenie prawe;
    	Wyrazenie lewe;

    	public Pomnoz (Wyrazenie pierwsze, Wyrazenie drugie)
    	{
        	lewe = pierwsze;
        	prawe = drugie;
		wartosc = lewe.wartosc * prawe.wartosc;
		wyrazenie = "(" + lewe.wyrazenie + " * " + prawe.wyrazenie + ")";
    	}
}
class Podziel extends Wyrazenie
{
    	Wyrazenie prawe;
    	Wyrazenie lewe;

    	public Podziel (Wyrazenie pierwsze, Wyrazenie drugie) throws ArithmeticException
    	{
        	lewe = pierwsze;
        	prawe = drugie;
		if (prawe.wartosc==0)
			throw new ArithmeticException("Nie mozna dzielic przez 0!");
		wartosc = lewe.wartosc / prawe.wartosc;
		wyrazenie ="(" + lewe.wyrazenie + " / " + prawe.wyrazenie + ")";
    	}
}

class Wyrazenie
{
	int wartosc;
	String wyrazenie;

	public int oblicz()
	{
		return wartosc;
	}
	
	public String toString()
    	{
		return wyrazenie;
	}
}

public class Lisc extends Wyrazenie
{
	static Hashtable<Character, Integer> zmienna = new Hashtable<Character, Integer>();

	Lisc(int x)
	{
		wartosc=x;
		wyrazenie=String.valueOf(x);
	}
	Lisc(char x)
	{
		wartosc=zmienna.get(x);
		wyrazenie=String.valueOf(wartosc);
	}
	public static void main(String[] args)
 
	{ 

		zmienna.put('x', 12);
		zmienna.put('y', 15);

		Wyrazenie wyr1 = new Dodaj(new Lisc(5), new Lisc('x'));
		Wyrazenie wyr2 = new Odejmij(wyr1, new Lisc('y'));
		System.out.println(wyr2.toString() + " = " + wyr2.oblicz());

		Wyrazenie wyr3 = new Pomnoz(wyr2, new Lisc(9));
		System.out.println(wyr3.toString() + " = " + wyr3.oblicz());

		Wyrazenie wyr4 = new Podziel(wyr3, new Lisc(3));
		System.out.println(wyr4.toString() + " = " + wyr4.oblicz());

		Wyrazenie wyr5 = new Podziel(new Lisc('x'), wyr4);
		System.out.println(wyr5.toString() + " = " + wyr5.oblicz());
	}
}
