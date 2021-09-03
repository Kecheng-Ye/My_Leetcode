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

// Like problem 110
class Solution {
    private int ans = 0;
    // Time: O(n), Space: O(1)
    public int diameterOfBinaryTree(TreeNode root) {
        MaxDepth(root);
        return ans;
    }
    
    private int MaxDepth(TreeNode root){
        if(root == null) return 0;
        int left = MaxDepth(root.left);
        int right = MaxDepth(root.right);
        if((left + right) > ans) ans = left + right;
        return Math.max(left, right) + 1;
    }
}