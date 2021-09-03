class TreeNode {
    public int val;
    public TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class BST {
    public TreeNode root;

    public BST() {
    }

    public boolean isValid() {
        return isValid_helper(root, new TreeNode(Integer.MIN_VALUE), new TreeNode(Integer.MAX_VALUE));
    }

    public boolean isValid_helper(TreeNode root, TreeNode min, TreeNode max) {
        if (root == null)
            return true;

        if (root.val <= min.val)
            return false;
        if (root.val >= max.val)
            return false;

        return isValid_helper(root.left, min, root) && isValid_helper(root.right, root, max);

    }

    public void insert(int val) {
        if (root == null) {
            root = new TreeNode(val);
            return;
        }

        insert_helper(root, val);
    }

    private TreeNode insert_helper(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);

        if (root.val > val) {
            root.left = insert_helper(root.left, val);
        } else {
            root.right = insert_helper(root.right, val);
        }

        return root;
    }

    public boolean search(int val) {
        return search_helper(root, val);
    }

    private boolean search_helper(TreeNode root, int val) {
        if (root == null)
            return false;

        if (root.val == val)
            return true;

        if (root.val > val) {
            return search_helper(root.left, val);
        } else {
            return search_helper(root.right, val);
        }
    }

    public void delete(int val) {
        delete_helper(root, val);
    }

    public TreeNode delete_helper(TreeNode root, int val) {
        if (root == null)
            return null;

        if (root.val == val) {
            if (root.left == null && root.right == null)
                return null;

            if (root.left == null || root.right == null) {
                return (root.left == null) ? root.right : root.left;
            }

            int min_of_right = FindMin(root.right);
            root.val = min_of_right;
            root.right = delete_helper(root.right, min_of_right);
        } else if (val < root.val) {
            root.left = delete_helper(root.left, val);
        } else {
            root.right = delete_helper(root.right, val);
        }

        return root;
    }

    private int FindMin(TreeNode root) {
        if (root.left == null)
            return root.val;
        return FindMin(root.left);
    }

    private int FindMax(TreeNode root) {
        if (root.right == null)
            return root.val;
        return FindMax(root.right);
    }

    public void print() {
        print_helper(root);
    }

    public void print_helper(TreeNode root) {
        if (root == null)
            return;

        print_helper(root.left);
        System.out.println(root.val);
        print_helper(root.right);
    }

    public static void main(String[] args) {
        BST tree = new BST();
        tree.insert(2);
        tree.insert(1);
        // tree.delete(1);
        tree.print();
    }
}