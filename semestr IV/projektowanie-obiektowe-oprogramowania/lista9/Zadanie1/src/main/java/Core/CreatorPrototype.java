package Core;

import java.lang.reflect.InvocationTargetException;

class CreatorPrototype implements Creator{

    Class<?> constructor;

    CreatorPrototype(Class<?> constructor) {
        this.constructor = constructor;
    }

    @Override
    public Object createObject() throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {

        return constructor.getConstructor((Class<?>[]) null).newInstance();

    }

}
