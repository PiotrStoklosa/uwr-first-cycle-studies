package zadanie1;

public class GetFTPCommand implements Command{

        private static final GetFTPReceiver getFTPReceiver;
        static{
            getFTPReceiver = new GetFTPReceiver();
        }

        private final String fileToDownload;

        public GetFTPCommand(String fileToDownload) {
            this.fileToDownload = fileToDownload;
        }

        @Override
        public void execute() {
            getFTPReceiver.action(fileToDownload);
        }
    }

