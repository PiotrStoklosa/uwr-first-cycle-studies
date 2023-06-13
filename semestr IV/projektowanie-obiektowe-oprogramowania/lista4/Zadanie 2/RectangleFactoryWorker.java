package Zadanie2;

public class RectangleFactoryWorker implements IShapeFactoryWorker {
    @Override
    public boolean AcceptParameters(String shapeName, Object[] parameters) {
        return shapeName.equals("Rectangle") && parameters.length == 2;
    }

    @Override
    public IShape CreateShape(String shapeName, Object[] parameters) {
        return new Rectangle(parameters[0], parameters[1]);
    }
}
