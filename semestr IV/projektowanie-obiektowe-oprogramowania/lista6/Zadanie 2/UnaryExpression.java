package Zad2;

public class UnaryExpression extends AbstractExpression {

    private final AbstractExpression expression;

    public UnaryExpression(AbstractExpression expression) {
        this.expression = expression;
    }

    @Override
    public boolean interpret(Context context) {
        return !expression.interpret(context);
    }
}
