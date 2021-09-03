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
    // Time: O(n), Space: O(n)
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null) return new LinkedList<Integer>();
        
        Stack<TreeNode> stack = new Stack<>();
        List<Integer> ans = new LinkedList<>();
        stack.add(root);
        TreeNode temp = root.left;
        
        while(temp != null || !stack.isEmpty()){
            // traverse to the left end first
            while(temp != null){
                stack.push(temp);
                temp = temp.left;
            }
            // then pop if
            TreeNode cur_Node = stack.pop();
            ans.add(cur_Node.val);
            temp = cur_Node.right;
        }
        
        return ans;
    }
}