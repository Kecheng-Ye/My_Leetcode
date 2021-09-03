/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class Solution {
    // Time: O(n), Space: O(1)
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        
        int root_val = root.val;
        if(root.left == null && root.right == null && sum - root_val == 0){
            return true;
        }
        
        return hasPathSum(root.left, sum - root_val) || hasPathSum(root.right, sum - root_val);     
    }
    
}