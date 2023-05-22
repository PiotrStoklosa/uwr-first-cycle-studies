//Piotr Stoklosa Zadanie2
using System;
using Biblioteka_Zadanie2Lista3;
namespace Testy_Zadanie2Lista3
{
    class Program
    {
        static void Main()
        {
            Dictionary<string, int> slownik = new Dictionary<string, int>();
            Console.WriteLine("Dodaj do slownika: (Zadanie,2), (Lista, 3), (Godzina, 17)\n");
            slownik.Add_Element("Zadanie", 2);
            slownik.Add_Element("Lista", 3);
            slownik.Add_Element("Godzina", 17);

            Console.WriteLine("Wyszukaj element o kluczu Lista i wyswietl jego wartosc");
            Console.WriteLine(slownik.Search("Lista").val);

            Console.WriteLine("Wyszukaj element o kluczu Godzina i wyswietl jego wartosc");
            Console.WriteLine(slownik.Search("Godzina").val);

            Console.WriteLine("Wyszukaj element o kluczu Lista i wyswietl jego wartosc");
            Console.WriteLine(slownik.Search("Lista").val);
            Console.WriteLine("");

            Console.WriteLine("Usun element o kluczu Lista i wyswietl jego wartosc");
            Console.WriteLine(slownik.Erase("Lista").val);

            Console.WriteLine("Usun element o kluczu Godzina i wyswietl jego wartosc");
            Console.WriteLine(slownik.Erase("Godzina").val);

            Console.WriteLine("Usun element o kluczu Zadanie i wyswietl jego wartosc");
            Console.WriteLine(slownik.Erase("Zadanie").val);

        }
    }
}
