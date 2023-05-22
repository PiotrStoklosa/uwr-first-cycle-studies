//Piotr Stoklosa Zadanie1
using System;
using Biblioteka_Zadanie1Lista3;
namespace Testy_Zadanie1Lista3
{
    class Program
    {
        static void Main()
        {
            Lista<int> lista = new Lista<int>();
            lista.Add_End_Element(5);
            lista.Add_End_Element(19);
            Console.WriteLine("Lista z dodaniem 5 i 9 na koniec listy");
            lista.Write_List();

            lista.Add_Start_Element(4);
            Console.WriteLine("Lista z dodaniem 4 na poczatek listy");
            lista.Write_List();

            Console.WriteLine("Usuniecie pierwszego elementu z listy, czyli elementu o wartosci: ");
            Console.WriteLine(lista.Erase_Start_Element().val);

            Console.WriteLine("Usuniecie ostatniego elementu z listy, czyli elementu o wartosci: ");
            Console.WriteLine(lista.Erase_Last_Element().val);

            Console.WriteLine("Lista po usunieciu ostatniego i pierwszego elementu");
            lista.Write_List();

            Console.WriteLine("Czy lista jest niepusta?");
            if (lista.non_empty() == true)
                Console.WriteLine("TAK");
            else
                Console.WriteLine("NIE");

            Console.WriteLine("Usuniecie ostatniego elementu z listy, czyli elementu o wartosci: ");
            Console.WriteLine(lista.Erase_Last_Element().val);

            Console.WriteLine("Czy lista jest niepusta?");
            if (lista.non_empty() == true)
                Console.WriteLine("TAK");
            else
                Console.WriteLine("NIE");
        }
    }
}
