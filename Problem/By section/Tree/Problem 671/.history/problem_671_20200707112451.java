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
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null) return -1;
        
        return DFS_helper(root, root.val);
    }
    
    public int DFS_helper(TreeNode root, int min_val){
        if(root == null) return -1;
        
        if(root.val > min_val) return root.val;
        
        int left_min = DFS_helper(root.left, min_val);
        int right_min = DFS_helper(root.right, min_val);
        
        if(left_min == -1) return right_min;
        if(right_min == -1) return left_min;
        
        return Math.min(left_min, right_min);
    }
       
}