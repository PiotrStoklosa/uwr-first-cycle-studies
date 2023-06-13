package Zad2;

public class ConstExpression extends  AbstractExpression {

    private String name;
    private final boolean isVariable;
    private boolean value;

    public ConstExpression(String name) {
        this.isVariable = true;
        this.name = name;
    }

    public ConstExpression(boolean value) {
        this.isVariable = false;
        this.value = value;
    }

    @Override
    public boolean interpret(Context context) {

        return isVariable ? context.getValue(name) : value;

    }
}