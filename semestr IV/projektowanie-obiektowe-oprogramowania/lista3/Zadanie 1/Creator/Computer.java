package zadanie1.creator;

public class Computer {

    private Keyboard keybord;

    public Computer(Keyboard keybord) {
        this.keybord = keybord;
    }

    public Keyboard keybordCrator(int numberOfKeys){

        return new Keyboard(numberOfKeys);

    }


}
