package Core;

import org.junit.Assert;
import java.lang.reflect.InvocationTargetException;

public class Test {

    @org.junit.Test
    public void testConcatenate() throws InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException, NoInterfaceImplementationFoundException, ClassNotFoundException {

        SimpleContainer c = new SimpleContainer();

        c.RegisterType( Foo.class, true );
        Foo f1 = c.Resolve( Foo.class);
        Foo f2 = c.Resolve( Foo.class);

        Assert.assertEquals(f1, f2);

    }

    @org.junit.Test
    public void testInterfaces() throws InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException, NoInterfaceImplementationFoundException, ClassNotFoundException {

        SimpleContainer c = new SimpleContainer();

        c.RegisterType(IFoo.class, Foo.class, false );
        IFoo f = c.Resolve(IFoo.class);

        Assert.assertTrue(f instanceof Foo);

        c.RegisterType( IFoo.class, Bar.class, false );
        IFoo g = c.Resolve(IFoo.class);

        Assert.assertTrue(g instanceof Bar);

    }

    @org.junit.Test(expected = NoInterfaceImplementationFoundException.class)
    public void testNoInterfaceImplementation() throws NoInterfaceImplementationFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException, ClassNotFoundException {

        SimpleContainer c = new SimpleContainer();

        IFoo f = c.Resolve(IFoo.class);

    }

    @org.junit.Test
    public void testNoConcreteClass() throws NoInterfaceImplementationFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException, ClassNotFoundException {

        SimpleContainer c = new SimpleContainer();

        Foo f = c.Resolve( Foo.class);

    }

}