package Zadanie5;

import java.util.List;

public abstract class PersonRegistryLoader {

    protected PersonLoader loader;

    public PersonRegistryLoader(PersonLoader loader) {
        this.loader = loader;
    }

    public abstract void notifyPersons();

    public List<Person> getPersons() {
        return loader.getPersons();
    }
}