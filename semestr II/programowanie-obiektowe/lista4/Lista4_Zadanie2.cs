//Piotr Stoklosa Lista4 Zadanie2
using System;
using System.Collections;
using System.Collections.Generic;

namespace Lista4_Zadanie2
{
    public class PrimeCollection : IEnumerable
    {

        public int[] list = new int[1000000000];

        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }

        public IEnumerator GetEnumerator()
        {
            return new ListEnum(list);
        }

    }

    public class ListEnum : IEnumerator
    {
        public bool IsPrime(int val)
        {
            if (val == 2)
                return true;
            if (val <= 1 || val % 2 == 0)
                return false;

            for (int i = 3; i <= (int)Math.Floor(Math.Sqrt(val)); i += 2)
                if (val % i == 0)
                    return false;
            return true;
        }


        public int[] list = new int[1000000000];
        public int pos = 0;
        public ListEnum(int[] list)
        {
            this.list = list;
        }
        public bool MoveNext()
        {
            int el;
            this.pos++;
            el = this.list[pos - 1];

            for (int i = el + 1; i > 0; i++)
            {
                if (IsPrime(i))
                {
                    this.list[pos] = i;
                    return true;
                }
            }
            return false;
        }
        public void Reset()
        {
            this.pos = 0;
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
                return this.list[pos];
            }
        }

    }
    class Program
    {
        static void Main()
        {
           /* PrimeCollection pc = new PrimeCollection(); 
            foreach (int p in pc) 
                Console.WriteLine (p);*/
        }
    }
}
