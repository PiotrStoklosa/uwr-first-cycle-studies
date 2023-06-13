package Zadanie2;

import static junit.framework.TestCase.assertNotNull;

public class Test2 {

    @org.junit.Test
    public void Test2klient() throws Exception {

        ShapeFactory factory = new ShapeFactory();
        IShape square = factory.CreateShape("Square", new Object[]{5});

        assertNotNull(square);
    }

    @org.junit.Test
    public void Test2rozszerzenie() throws Exception {

        ShapeFactory factory = new ShapeFactory();

        factory.RegisterWorker( new RectangleFactoryWorker() );
        IShape rect = factory.CreateShape( "Rectangle", new Object[]{3, 5} );

        assertNotNull(rect);
    }

}
