package Zadanie2;

public class ShapeFactoryWorker implements IShapeFactoryWorker{
    @Override
    public boolean AcceptParameters(String shapeName, Object[] parameters) {
        return shapeName.equals("Square") && parameters.length == 1;
    }

    @Override
    public IShape CreateShape(String shapeName, Object[] parameters) {
        return new Square(parameters[0]);
    }
}
