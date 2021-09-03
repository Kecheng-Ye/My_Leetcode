class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int cur_sum = 0;    

    public TreeNode convertBST(TreeNode root) {
        DFS(root);
        return root;
    }
    
    public void DFS(TreeNode root){
        if(root == null) return;
        
        DFS(root.right);
        
        cur_sum += root.val;
        root.val = cur_sum;
        
        
        DFS(root.left);
    }
}