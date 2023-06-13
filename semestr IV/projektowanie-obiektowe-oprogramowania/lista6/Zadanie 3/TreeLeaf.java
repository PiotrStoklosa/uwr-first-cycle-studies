package Zad3;

public class TreeLeaf extends Tree {

    private final int value;

    public TreeLeaf(int value) {
        this.value = value;
    }

    @Override
    public void accept(TreeVisitor visitor) {
        visitor.visitLeaf(this);
    }
}