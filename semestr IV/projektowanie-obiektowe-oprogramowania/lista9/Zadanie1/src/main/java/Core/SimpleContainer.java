package Core;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Type;
import java.util.HashMap;
import java.util.Map;

public class SimpleContainer {

    private final Map<String, Creator> creators;
    {
        creators = new HashMap<>();
    }

    public void RegisterType(Type type, boolean singleton) {

        RegisterType(type, type, singleton);

    }

    public void RegisterType(Type type1, Type type2, boolean singleton){

        Class<?> aClass = null;
        try {
            aClass = Class.forName(type2.getTypeName());
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        if (singleton)
            creators.put(type1.getTypeName(), new CreatorSingleton(aClass));
        else
            creators.put(type1.getTypeName(), new CreatorPrototype(aClass));

    }

    @SuppressWarnings("unchecked")
    public <T> T Resolve(Type type) throws InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException, NoInterfaceImplementationFoundException, ClassNotFoundException {

        Class<?> aClass = null;
        try {
            aClass = Class.forName(type.getTypeName());
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        assert aClass != null;
        if (!creators.containsKey(type.getTypeName())){
            if (aClass.isInterface())
                throw new NoInterfaceImplementationFoundException();

            return (T) Class.forName(type.getTypeName()).getConstructor((Class<?>[]) null).newInstance();
        }

        return (T) creators.get(type.getTypeName()).createObject();

    }

}