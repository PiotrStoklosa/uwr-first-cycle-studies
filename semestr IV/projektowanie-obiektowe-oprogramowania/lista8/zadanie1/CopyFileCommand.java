package zadanie1;

public class CopyFileCommand implements Command{

    private static final CopyFileReceiver copyFileReceiver;
    static{
        copyFileReceiver = new CopyFileReceiver();
    }

    private final String sourceFile;
    private final String targetFile;


    public CopyFileCommand(String sourceFile, String targetFile) {
        this.sourceFile = sourceFile;
        this.targetFile = targetFile;
    }

    @Override
    public void execute() {
        copyFileReceiver.action(sourceFile, targetFile);
    }
}
