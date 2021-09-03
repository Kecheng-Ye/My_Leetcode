import apple.laf.JRSUIUtils.Tree;

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

    public boolean isValid(){
        return isValid_helper(root, new TreeNode(Integer.MIN_VALUE), new TreeNode(Integer.MAX_VALUE));
    }

    public boolean isValid_helper(TreeNode root, TreeNode min, TreeNode max){
        if(root == null) return true;

        if(root.val <= min.val) return false;
        if(root.val >= max.val) return false;

        return isValid_helper(root.left, min, root) &&
               isValid_helper(root.right, root, max);

    }

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
        return search_helper(root, val);
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
    
    public String toString(){
        
    }
}