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
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return null;
        // first reverse the left subtree and right substree
        TreeNode temp = invertTree(root.left);
        root.left = invertTree(root.right);
        // and reverse the left subtree to right branch
        // right subtree to left branch
        root.right = temp;
        
        return root;
    }
}