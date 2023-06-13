package zadanie4;

public class Square implements Shape{

    private int a;

    public Square(int a){

        this.a = a;

    }

    @Override
    public int CalculateArea() {
        return a * a;
    }

}
