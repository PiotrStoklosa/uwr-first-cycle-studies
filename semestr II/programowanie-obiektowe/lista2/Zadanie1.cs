//Piotr Stoklosa, Zadanie 1
using System;

class IntStream{

	public int actual_number=0;

	virtual public int next(){
		return actual_number++;
	}
	virtual public bool eos(){
		if (actual_number<0)
			return true;
		return false;
	}
	public void reset(){
		actual_number=0;
	}
}
class PrimeStream: IntStream{
	bool prime(int number){
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
	override public int next(){
		base.next();
		while(!prime(actual_number))
			base.next();
		return actual_number;
	}
}
class RandomStream: IntStream{
	Random generator = new Random();
	override public int next(){
		return generator.Next();
		}
	override public bool eos(){
		return false;	
	}
	
}
class RandomWordStream{
	PrimeStream prime = new PrimeStream();
	Random gen = new Random();
	public string next()
	{
		
		int x = prime.next(); 
		string word="";
		for (int i=0; i<x; i++)
			word+=(char)((gen.Next() % 94 + 33));
		return word;
	}
}
class MojProgram {
	public static void Main() {
		RandomWordStream rws = new RandomWordStream();
		for (int i=0; i<8; i++)
			Console.WriteLine(rws.next());
		}
}

