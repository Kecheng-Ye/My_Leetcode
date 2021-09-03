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
    private int ans = 0;
    
    // Time: O(nlogn), Space: O(1)
    public int longestUnivaluePath(TreeNode root) {
        if(root == null) return 0;
        helper(root);
        
        // since I will check every root once
        // and by checking each root's longestUnivaluePath, the program will get to the same node multiple times
        longestUnivaluePath(root.left);
        longestUnivaluePath(root.right);
        return ans;
    }
    
    // helper function returning the maxmial depth of tree such that all of node val within this tree is the same
    // also will update the global longestUnivaluePath value wihtin the function
    private int helper(TreeNode root){
        if(root == null) return 0;

        int left_branch = (root.left != null && root.left.val == root.val) ? helper(root.left) : 0;
        int right_branch = (root.right != null && root.right.val == root.val) ? helper(root.right) : 0;
        ans = Math.max(ans, left_branch + right_branch);
        
        return 1 + Math.max(left_branch, right_branch);
    }
    
}