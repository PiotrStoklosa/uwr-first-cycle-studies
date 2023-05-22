//Piotr Stoklosa zad 1
import java.io.*;
import java.util.*;


class Rank implements Comparable<Rank>
{
	Integer level=0;
	public Integer get_Rank()
    	{
        	return level;
    	}
	@Override
	public int compareTo(Rank o)
	{
		if (this.get_Rank() > o.get_Rank()) return 1;
		if (this.get_Rank() == o.get_Rank()) return 0;
		return -1;
	}
}
class Szeregowy extends Rank
{
	Szeregowy()
	{
		level = 1;
	}
}
class Kapral extends Rank
{
	Kapral()
	{
		level = 2;
	}
}
class Sierzant extends Rank
{
	Sierzant()
	{
		level = 3;
	}
}
class Chorazy extends Rank
{
	Chorazy()
	{
		level = 4;
	}
}
public class Kolekcja
{
	List<Rank> kol = new ArrayList<Rank>();
	void Add(Rank x)
	{
		for (int i=0; i<kol.size(); i++)
			if (x.compareTo(kol.get(i)) <= 0)
				{
					kol.add(i,x);
					return;
				}
		kol.add(x);
		return;
	}
	Rank Remove()
	{
		Rank minimum = kol.get(0);
		kol.remove(0);
		return minimum;
	}
	void Write()
	{
		for (Rank elem : kol)
			System.out.println(elem);
		
	}
	
	public static void main(String[] args)
 
	{ 
		System.out.println("Stworzenie kolekcji i dodanie kilku elementow");
		Kolekcja ranks = new Kolekcja();
		ranks.Add(new Chorazy());
		ranks.Add(new Kapral());
		ranks.Add(new Szeregowy());
		ranks.Add(new Chorazy());
		ranks.Write();
		System.out.println();

		System.out.println("Kolekcja po usunieciu elementu");
		ranks.Remove();
		ranks.Write();
		System.out.println();

		System.out.println("Kolekcja po dodaniu elementu Sierzant");
		ranks.Add(new Sierzant());
		ranks.Write();
	}
}
