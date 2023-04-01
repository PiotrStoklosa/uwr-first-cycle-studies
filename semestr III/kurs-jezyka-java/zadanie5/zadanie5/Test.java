import structures.OrderedList;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Test {
    public static void main(String[] args) throws Exception {
        System.out.println("Utworzenie listy <Integer> i dodanie kilku elementów");
        OrderedList<Integer> lista1 = new OrderedList<>(5);
        lista1.insert(8);
        lista1.insert(10);
        lista1.insert(6);
        lista1.insert(4);

        for (int i : lista1)
            System.out.print(i + " ");
        System.out.println("\n");

        System.out.println("Usunięcie elementu 6");
        lista1.remove(6);
        for (int i : lista1)
            System.out.print(i + " ");
        System.out.println("\n");

        System.out.println("Max listy");
        System.out.println(lista1.max());

        System.out.println("\nMin listy");
        System.out.println(lista1.min());

        System.out.println("\nPobranie elementu na pozycji nr 2");
        System.out.println(lista1.at(2));

        System.out.println("\nCzy element 7 znajduje sie w liscie?");
        System.out.println(lista1.search(7));

        System.out.println("\nCzy element 8 znajduje sie w liscie?");
        System.out.println(lista1.search(8));

        System.out.println("\nZwroc indeks elementu 10");
        System.out.println(lista1.index(10));


        System.out.println("\n\n\nUtworzenie listy <String> i dodanie kilku elementów");
        OrderedList<String> lista2 = new OrderedList<>("Celina");
        lista2.insert("Agata");
        lista2.insert("Dawid");
        lista2.insert("Bogdan");
        lista2.insert("Agnieszka");

        for (String i : lista2)
            System.out.print(i + " ");
        System.out.println("\n");

        System.out.println("Usunięcie elementu 'Agnieszka'");
        lista2.remove("Agnieszka");
        for (String i : lista2)
            System.out.print(i + " ");
        System.out.println("\n");

        System.out.println("Max listy");
        System.out.println(lista2.max());

        System.out.println("\nMin listy");
        System.out.println(lista2.min());

        System.out.println("\nPobranie elementu na pozycji nr 1");
        System.out.println(lista2.at(2));

        System.out.println("\nCzy element 'Agnieszka' znajduje sie w liscie?");
        System.out.println(lista2.search("Agnieszka"));

        System.out.println("\nCzy element 'Celina' znajduje sie w liscie?");
        System.out.println(lista2.search("Celina"));

        System.out.println("\nZwroc indeks elementu 'Agata'");
        System.out.println(lista2.index("Agata"));

        System.out.println("\n\n\nUtworzenie listy <Calendar> i dodanie kilku elementów");


        OrderedList<Calendar> lista3 = new OrderedList<>(new GregorianCalendar(2000, Calendar.FEBRUARY,1,13,24,56));
        lista3.insert(new GregorianCalendar(2014, Calendar.OCTOBER,12,1,11,44));
        lista3.insert(new GregorianCalendar(2010, Calendar.APRIL,2,2,22,33));
        lista3.insert(new GregorianCalendar(2010, Calendar.JUNE,6,3,33,22));
        lista3.insert(new GregorianCalendar(2014, Calendar.OCTOBER,22,4,44,11));


        for (Calendar i : lista3)
            System.out.println(i.getTime() + " ");
        System.out.println("\n");

        System.out.println("Max listy");
        System.out.println(lista3.max().getTime());

        System.out.println("\nMin listy");
        System.out.println(lista3.min().getTime());

        System.out.println("\nPobranie elementu na pozycji nr 3");
        System.out.println(lista3.at(3).getTime());

        System.out.println("\nZwroc indeks elementu " + lista3.at(3).getTime());
        System.out.println(lista3.index(lista3.at(3)));
    }
}
