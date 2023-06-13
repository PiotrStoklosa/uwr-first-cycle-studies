package Zadanie2;

public interface IShapeFactoryWorker {

    boolean AcceptParameters(String shapeName, Object[] parameters);
    IShape CreateShape(String shapeName, Object[] parameters);

}
