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
    // Time: O(n), Space: O(n)
    public TreeNode convertBST(TreeNode root) {
        DFS(root);
        return root;
    }
    // first traverse right and then increment the sum
    // and the add it to the left part of the tree
    public void DFS(TreeNode root){
        if(root == null) return;
        
        DFS(root.right);
        
        cur_sum += root.val;
        root.val = cur_sum;
         
        DFS(root.left);
    }
}