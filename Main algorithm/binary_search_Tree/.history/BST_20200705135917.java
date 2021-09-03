class TreeNode{
    public int val;
    public TreeNode left, right;

    public TreeNode(int val){
        this.val = val;
    }
}

public class BST{
    public TreeNode root;

    public BST(){}

    public void insert(int val){
        if(root == null){
            root = new TreeNode(val);
            return;
        }

        insert_helper(root, val);
    }

    private TreeNode insert_helper(TreeNode root, int val){
        if(root == null) return new TreeNode(val);

        if(root.val > val){
            root.left = insert_helper(root.left, val);
        }else{
            root.right = insert_helper(root.right, val);
        }

        return root;
    }

    public boolean search(int val){

    }

    private boolean search_helper(TreeNode root, int val){
        if(root == null) return false;

        if(root.val == val) return true;

        if(root.val > val){
            return search_helper(root.left, val);
        }else{
            return search_helper(root.right, val);
        }
    }
    
}