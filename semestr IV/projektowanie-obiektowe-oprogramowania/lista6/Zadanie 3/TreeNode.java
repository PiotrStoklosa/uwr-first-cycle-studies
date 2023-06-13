package Zad3;

public class TreeNode extends Tree{

    private final Tree left;
    private final Tree right;

    public TreeNode(Tree left, Tree right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public void accept(TreeVisitor visitor) {
        visitor.visitNode(this);

        if (left != null)
            left.accept(visitor);
        if (right != null)
            right.accept(visitor);
    }

    public Tree getLeft() {
        return left;
    }

    public Tree getRight() {
        return right;
    }

}