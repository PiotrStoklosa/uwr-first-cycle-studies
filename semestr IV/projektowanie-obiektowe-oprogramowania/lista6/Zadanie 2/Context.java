package Zad2;

import java.util.HashMap;

public class Context {

    private final HashMap<String, Boolean> context;
    {
        context = new HashMap<>();
    }

    public boolean getValue(String name) {
        return context.get(name);
    }

    public void setValue(String name, boolean value) {
        context.put(name, value);
    }
}