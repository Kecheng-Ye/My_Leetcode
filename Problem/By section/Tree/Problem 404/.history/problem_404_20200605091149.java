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
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null) return 0;
        // important!!! since a left leaf can be placed in a right branch
        if(root.left == null) return sumOfLeftLeaves(root.right);
        // if we encounter a left leaf
        if(root.left.left == null && root.left.right == null) return root.left.val + sumOfLeftLeaves(root.right);
        
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
}