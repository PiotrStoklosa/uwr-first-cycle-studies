package zadanie1;

public class CreateRandomFileCommand implements Command{

        private static final CreateRandomFileReceiver createRandomFileReceiver;
        static{
            createRandomFileReceiver = new CreateRandomFileReceiver();
        }

        private final String fileToCreate;

        public CreateRandomFileCommand(String fileToCreate) {
            this.fileToCreate = fileToCreate;
        }

        @Override
        public void execute() {
            createRandomFileReceiver.action(fileToCreate);
        }
}
