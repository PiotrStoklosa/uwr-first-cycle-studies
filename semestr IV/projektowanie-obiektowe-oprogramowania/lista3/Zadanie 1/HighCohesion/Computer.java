package zadanie1.highcohesion;

public class Computer{

    private Keyboard keyboard;
    private Monitor monitor;
    private Camera camera;

    public Computer(Keyboard keyboard, Monitor monitor, Camera camera) {
        this.keyboard = keyboard;
        this.monitor = monitor;
        this.camera = camera;
    }
}