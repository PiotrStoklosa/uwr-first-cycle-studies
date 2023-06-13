package zadanie1;

import java.util.List;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {

        Invoker invoker = new Invoker();

        List<Command> commands = List.of(

                new CopyFileCommand("sourceFile.txt", "targetFile.txt"),
                new CreateRandomFileCommand("fileToCreate.txt"),
                new GetFTPCommand("fileToDownload.txt"),
                new GetHTTPCommand("fileToDownload.txt")

        );

        new Thread(() -> IntStream.range(0,4).mapToObj(commands::get).forEach(invoker::addCommand)).start();

        for (int i = 0; i < 2; i++) {

            new Thread(() -> {

                for (int j = 0; j < 3; j++) {

                    invoker.executeCommand();

                    try {

                        Thread.sleep(50);

                    } catch (InterruptedException e) {

                        e.printStackTrace();

                    }
                }

            }).start();

        }
    }
}
