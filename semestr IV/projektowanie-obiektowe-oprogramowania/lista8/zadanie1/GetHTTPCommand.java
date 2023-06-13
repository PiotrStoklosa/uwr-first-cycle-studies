package zadanie1;

public class GetHTTPCommand implements Command{

    private static final GetHTTPReceiver getHTTPReceiver;
    static{
        getHTTPReceiver = new GetHTTPReceiver();
    }

    private final String fileToDownload;

    public GetHTTPCommand(String fileToDownload) {

        this.fileToDownload = fileToDownload;

    }

    @Override
    public void execute() {
        getHTTPReceiver.action(fileToDownload);
    }

}
