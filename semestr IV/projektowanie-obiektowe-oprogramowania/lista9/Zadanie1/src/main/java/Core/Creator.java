package Core;

import java.lang.reflect.InvocationTargetException;

interface Creator {

    Object createObject() throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException;

}