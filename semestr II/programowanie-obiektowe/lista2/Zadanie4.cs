//Piotr Stoklosa, Zadanie 4
using System;
using System.Collections.Generic;
class Random_Number{
	Random generator = new Random();
	public int next(){
		return generator.Next();
	}
}
class ListaLeniwa{
	public List<int> lista= new List<int>();
	Random generator= new Random();
	virtual public int element(int i){
		for (int j=lista.Count; j<i; j++)
			lista.Add(generator.Next());
		return lista[i-1];
	}
	public int size(){
		return lista.Count;
	}
}
class Pierwsze: ListaLeniwa{
	int actual_number=2;
	public bool prime(int number){
		if (number<2)
			return false;
		if (number==2)
			return true;
		if (number%2==0)
			return false;
		for (int i=3; i*i<=number; i+=2)
			if (number%i==0)
				return false;
		return true;
	}
	override public int element(int i){
		for (int j=lista.Count; j<i; j++)
			{
				while(!prime(actual_number))
					actual_number++;
				lista.Add(actual_number++);
			}
		return lista[i-1];
		}
}
class MojProgram {
	public static void Main() {
			ListaLeniwa lista1= new ListaLeniwa();
			Console.WriteLine("Piąta liczba pseudolosowa: " + lista1.element(5));
			Console.WriteLine("Czwarta liczba pseudolosowa: " + lista1.element(4));
			Console.WriteLine("Ilość liczb pseudolosowych w tablicy: " + lista1.size());
			Console.WriteLine("Szósta liczba pseudolosowa: " + lista1.element(6));
			Console.WriteLine("Czwarta liczba pseudolosowa: " + lista1.element(4));
			Pierwsze lista= new Pierwsze();	
    			Console.WriteLine("Piąta liczba pierwsza: " + lista.element(5));
			Console.WriteLine("Ilość liczb pierwszych w tablicy: " + lista.size());
			Console.WriteLine("Szósta liczba pierwsza: " + lista.element(6));
			Console.WriteLine("Czwarta liczba pierwsza: " + lista.element(4));
		}
}
