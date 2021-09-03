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
    // Time: O(nlogn), Space: O(1)
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null) return false;
        return Subtree_start_with_head(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
        
    }
    
    // compare two tree both from the root node
    private boolean Subtree_start_with_head(TreeNode s, TreeNode t){
        if(t == null && s == null) return true;
        if(t == null || s == null) return false;
        
        if(s.val != t.val) return false;
        
        return Subtree_start_with_head(s.left, t.left) && Subtree_start_with_head(s.right, t.right);
    }
}