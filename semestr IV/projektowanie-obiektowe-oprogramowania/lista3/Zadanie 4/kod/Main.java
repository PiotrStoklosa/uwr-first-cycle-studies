package zadanie4;

public class Main {

    public static void main(String[] args) {

        int w = 4, h = 5;
        Shape square = new Square(w);

        Shape rect = new Rectangle(w,h);

        System.out.println("prostokąt o wymiarach " + w + " na " + h + " ma pole "  + rect.CalculateArea());

        System.out.println("kwadrat o boku " + w + " ma pole "  + square.CalculateArea());

    }

}
