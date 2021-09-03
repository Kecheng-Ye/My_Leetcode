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
        // if we reach the leaf node and the current sum correspond to the leaf node value
        // then there exsist a path that satisfy the orginal sum
        if(root.left == null && root.right == null && sum - root_val == 0){
            return true;
        }
        
        // if we dont reach end, try to take either left path or right path
        // either path success means there exsist a path
        return hasPathSum(root.left, sum - root_val) || hasPathSum(root.right, sum - root_val);     
    }
    
}