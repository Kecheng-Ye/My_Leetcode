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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null){
            return t2;
        }else if(t2 == null){
            return t1;
        }else{
            // first set left and right branch as the merged left and right subtree
            TreeNode ans = new TreeNode();
            ans.left = mergeTrees(t1.left, t2.left);
            ans.right = mergeTrees(t1.right, t2.right);
            // then merge the node itself
            ans.val = t1.val + t2.val;
            return ans;
        }
    }
}