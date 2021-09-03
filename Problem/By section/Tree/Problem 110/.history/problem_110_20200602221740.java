import java.util.*;

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
    public boolean isBalanced(TreeNode root) {
        return (boolean)helper(root)[0];
    }
    
    public Object[] helper(TreeNode root){
        if(root == null) return new Object[]{true, 0};
        
        Object[] left_branch = helper(root.left);
        Object[] right_branch = helper(root.right);
        
        if(!((boolean)left_branch[0] && (boolean)right_branch[0])){
            return new Object[]{false, 0};        
        }else{
            return new Object[]{((int)left_branch[1] - (int)right_branch[1]) <= 1, 
                      Math.max((int)left_branch[1], (int)right_branch[1]) + 1};        
        }
    }
}
