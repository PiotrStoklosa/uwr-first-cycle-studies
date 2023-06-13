package Zad2;

public class BinaryExpression extends AbstractExpression {

    private final AbstractExpression firstExpression;
    private final AbstractExpression secondExpression;
    private final String operator;

    public BinaryExpression(AbstractExpression firstExpression, AbstractExpression secondExpression, String operator) {
        this.firstExpression = firstExpression;
        this.secondExpression = secondExpression;
        this.operator = operator;
    }

    @Override
    public boolean interpret(Context context) {

        switch (operator){
            case "&&" -> {
                return firstExpression.interpret(context) && secondExpression.interpret(context);
            }
            case "||" -> {
                return firstExpression.interpret(context) || secondExpression.interpret(context);
            }
            default -> throw new IllegalArgumentException("Operator not defined");
        }
    }
}