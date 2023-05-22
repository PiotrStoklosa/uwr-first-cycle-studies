//Piotr Stoklosa
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;

class WydawnictwoCiagle extends Ksiazka{
	WydawnictwoCiagle()
	{
		super();
		typ= "WydawnictwoCiagle";
		Edycja_nazwa = "Edycja- Wydawnictwo Ciagle";
	}		
}
class Czasopismo extends Ksiazka{
	Czasopismo()
	{
		super();
		typ= "Czasopismo";
		Edycja_nazwa = "Edycja- Czasopismo";
	}
}

public class Ksiazka extends JComponent implements ActionListener, Serializable{

	protected String Edycja_nazwa;
	protected String typ;
	protected String tytul;
	protected String autor;
	protected Integer wydanie;

	public String Plik;

	protected JButton b;
	protected JButton c;
	protected JFrame frame;

	protected JTextField autor_text;
	protected JTextField tytul_text;
	protected JTextField wydanie_text;
	
	String gettytul()
	{
		return tytul;
	}
	String getautor()
	{
		return autor;
	}
	int getwydanie()
	{
		return wydanie;
	}

	@Override
	public String toString(){
		return "Typ: " + typ.toString() + "\nTytul: " + tytul.toString() + "\nAutor: " + autor.toString() + "\nWydanie: " + wydanie.toString() + "\n";
	}

	public void Edycja() throws Exception
	{
		frame = new JFrame(Edycja_nazwa);
      	  	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container kontener = frame.getContentPane();
		GridLayout layout = new GridLayout(10, 20);

		kontener.setLayout(layout);

		JLabel typ_ksiazki = new JLabel("Typ: " + typ);
		kontener.add(typ_ksiazki);
		
		JLabel autor_etykieta = new JLabel("Autor: " + autor);
		kontener.add(autor_etykieta);
		autor_text = new JTextField(this.autor, 50);
		kontener.add(autor_text);


		JLabel tytul_etykieta = new JLabel("Tytul: " + tytul);
		kontener.add(tytul_etykieta);
		tytul_text = new JTextField(this.tytul, 50);
		kontener.add(tytul_text);

		JLabel wydanie_etykieta = new JLabel("Wydanie: " + wydanie);
		kontener.add(wydanie_etykieta);
		wydanie_text = new JTextField(Integer.toString(this.wydanie), 50);
		kontener.add(wydanie_text);

		b = new JButton("Zapisz");
		b.addActionListener(this);
		kontener.add(b);
		
		c = new JButton("Zapisz i wyjdz");
		c.addActionListener(this);
		kontener.add(c);

		frame.setSize(500,500);
		frame.setVisible(true);
	}

	public Ksiazka()
	{
		Edycja_nazwa = "Edycja- Ksiazka";
		typ = "Ksiazka";
		tytul = "";
		autor = "";
		wydanie = 0;
	}
	Ksiazka odczyt() throws Exception
	{
		
		Ksiazka temp = new Ksiazka ();
		temp.Plik = Plik;
		File f=new File(Plik);
		if(f.length()!=0)
		{
			ObjectInputStream in = new ObjectInputStream(
                        	new BufferedInputStream(
                        	new FileInputStream(Plik)));

				temp = (Ksiazka) in.readObject();
				in.close();
		}
		else
		{
			temp.typ=typ;
			temp.Edycja_nazwa=Edycja_nazwa;
		}
		return temp;
	}

	@Override
 	public void actionPerformed(ActionEvent e){
 		Object source = e.getSource();

		String pom = autor_text.getText();
		autor=pom;
   
		pom = tytul_text.getText();
		tytul=pom;

		pom = wydanie_text.getText();
		wydanie=Integer.parseInt(pom);

		try{
		zapisz();
		}
		catch (Exception blad) {
            		blad.printStackTrace();
       		}

		if(source == c)
 		{
			frame.setVisible(false);
			frame.dispose();
		}
		else if(source == b){
			Ksiazka temp = new Ksiazka ();

			try{
			temp = odczyt();
			}

			catch (Exception blad) {
            			blad.printStackTrace();
       			}

			frame.setVisible(false);
			frame.dispose();

			try{
			temp.Edycja();
			}

			catch (Exception blad) {
            			blad.printStackTrace();
       			}
		}
 	}
	void zapisz() throws Exception

	{	try{
		ObjectOutputStream out = new ObjectOutputStream(
                	new BufferedOutputStream(
                        	new FileOutputStream(Plik)));
		out.writeObject(this);
		out.close();
		}

		catch (Exception blad) {
            		blad.printStackTrace();
       		}
	}
	
	public static void main(String[] args) throws Exception{

		Ksiazka Book_from_file;

		if(args[1].equalsIgnoreCase("Ksiazka"))
			Book_from_file = new Ksiazka();

		else if(args[1].equalsIgnoreCase("Czasopismo"))
			Book_from_file = new Czasopismo();

		else if(args[1].equalsIgnoreCase("WydawnictwoCiagle"))
			Book_from_file = new WydawnictwoCiagle();

		else
		{
			System.out.println("Nie ma stworzonej takiej klasy!");
			return;
		}

		Book_from_file.Plik = args[0];
		Book_from_file = Book_from_file.odczyt();
		Book_from_file.Edycja();	
	}

}

