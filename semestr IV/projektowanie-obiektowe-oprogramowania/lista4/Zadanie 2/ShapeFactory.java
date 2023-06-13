package Zadanie2;

import java.util.ArrayList;
import java.util.List;

public class ShapeFactory {

    private final List<IShapeFactoryWorker> workers = new ArrayList<>();

    public ShapeFactory(){
        workers.add(new ShapeFactoryWorker());
    }

    public void RegisterWorker (IShapeFactoryWorker IshapeFactoryWorker){

        workers.add(IshapeFactoryWorker);

    }

    public IShape CreateShape( String shapeName, Object[] parameters) throws Exception {


        for (IShapeFactoryWorker worker:
                workers) {
            if (worker.AcceptParameters(shapeName, parameters))
                return worker.CreateShape(shapeName, parameters);
        }

        throw new Exception("I did not find appropriate worker");

    }



}
