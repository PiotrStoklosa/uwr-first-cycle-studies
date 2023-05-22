//Piotr Stoklosa Lista4 Zadanie1
using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace Lista4_Zadanie1
{

	interface Lista_intarface
	{
		int size();
		int element(int i);
	}
	class Random_Number
	{
		Random generator = new Random();
		public int next()
		{
			return generator.Next();
		}
	}
	class ListaLeniwa : Lista_intarface, IEnumerable
	{
		public List<int> lista = new List<int>();
		int licznik = 0;
		Random generator = new Random();
		public int element(int i)
		{
			for (int j = licznik; j < i; j++)
			{
				lista.Add(generator.Next());
				licznik++;
			}
			return lista[i - 1];
		}
		public int size()
		{
			return licznik;
		}
		public int Length
		{
			get
			{
				return this.size();
			}
		}
		public int this[int index]
		{
			get
			{
				return element(index + 1);
			}
			set
			{
				if (index >= this.size())
					element(index + 1);
				lista[index] = value;
			}
		}
		public override string ToString()
		{
			string s="";
			for (int i = 0; i < licznik; i++)
			{
				s+= this[i].ToString();
				if (i + 1 != licznik) s += ", ";
			}
			return s.ToString();
		}
		IEnumerator IEnumerable.GetEnumerator()
		{
			return (IEnumerator)GetEnumerator();
		}

		public IEnumerator GetEnumerator()
		{
			return new ListaLeniwaEnum(lista);
		}
	}
	class ListaLeniwaEnum : IEnumerator
	{

		public List<int> lista = new List<int>();

		int position = -1;

		public ListaLeniwaEnum(List<int> lista)
		{
			this.lista = lista;
		}

		public bool MoveNext()
		{
			position++;
			return (position < lista.Count);
		}

		public void Reset()
		{
			position = -1;
		}

		object IEnumerator.Current
		{
			get
			{
				return Current;
			}
		}

		public int Current
		{
			get
			{
				return this.lista[position];
			}
		}
	}
	class Pierwsze : Lista_intarface
	{
		public List<int> lista = new List<int>();
		int actual_number = 2;
		public bool prime(int number)
		{
			if (number < 2)
				return false;
			if (number == 2)
				return true;
			if (number % 2 == 0)
				return false;
			for (int i = 3; i * i <= number; i += 2)
				if (number % i == 0)
					return false;
			return true;
		}
		public int element(int i)
		{
			for (int j = lista.Count; j < i; j++)
			{
				while (!prime(actual_number))
					actual_number++;
				lista.Add(actual_number++);
			}
			return lista[i - 1];
		}
		public int size()
		{
			return lista.Count;
		}
	}
	class Program
	{
		static void Main()
		{
			ListaLeniwa lista1 = new ListaLeniwa();
			lista1[5] = 54;
			Console.WriteLine("Dodanie 5 losowych liczb oraz liczby 54 (Poprzez lista1[5] = 54): ");
			foreach (int p in lista1)
				Console.WriteLine(p);
			Console.WriteLine();

			lista1[6] = 999;
			Console.WriteLine("Dodanie liczby 999 i wyswietlenie listy: ");
			Console.WriteLine(lista1.ToString());
			Console.WriteLine();

			Console.WriteLine("Dlugosc listy: ");
			Console.WriteLine(lista1.Length);

		}
	}
}
