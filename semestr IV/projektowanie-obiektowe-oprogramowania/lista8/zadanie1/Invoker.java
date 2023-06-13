package zadanie1;

import java.util.LinkedList;
import java.util.Queue;

public class Invoker {

    private static final Queue<Command> commands;
    static{
        commands = new LinkedList<>();
    }

    public synchronized void addCommand(Command command) {
        commands.add(command);
    }

    public synchronized void executeCommand() {

        if (commands.size() > 0)
            commands.remove().execute();
        else
            System.out.println("\nQueue is empty!\n");

    }
}
