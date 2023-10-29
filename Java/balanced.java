public class balanced {
    int checkHeight(Treenode root)
    {
        if (root == null) return -1;

        int leftHeight = checkHeight(root.left);
        if(leftHeight == Integer.MIN_VALUE) return Integer.MIN_VALUE;

        int rightHeight = checkHeight(root.right);
        if(rightHeight == Integer.MIN_VALUE) return Integer.MIN_VALUE;

        int heigtDiff = leftHeight - rightHeight; 
        if (Math.abs(heightDiff) > 1)
        {
            return Integer
        }
    }

}
