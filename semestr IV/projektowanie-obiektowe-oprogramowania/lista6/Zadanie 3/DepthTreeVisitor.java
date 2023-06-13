package Zad3;

public class DepthTreeVisitor extends TreeVisitor {

    private int currentDepth;
    {
        currentDepth = 1;
    }
    private int depth;
    {
        depth = 1;
    }

    @Override
    public void visitNode(TreeNode node) {
        currentDepth++;
        node.getLeft().accept(this);
        node.getRight().accept(this);
        currentDepth--;
    }

    @Override
    public void visitLeaf(TreeLeaf leaf) {
        if (currentDepth > depth)
            depth = currentDepth;
    }

    public int getDepth() {
        return depth;
    }
}