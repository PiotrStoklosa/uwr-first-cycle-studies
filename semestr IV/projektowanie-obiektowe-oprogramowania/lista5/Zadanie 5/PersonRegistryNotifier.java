package Zadanie5;

import java.util.List;

public abstract class PersonRegistryNotifier {

    protected PersonNotifier notifier;

    public PersonRegistryNotifier(PersonNotifier notifier) {
        this.notifier = notifier;
    }

    public abstract List<Person> getPersons();

    public void notifyPersons() {

        List<Person> persons = getPersons();

        for (Person person : persons) {
            this.notifier.notify(person);
        }
    }
}