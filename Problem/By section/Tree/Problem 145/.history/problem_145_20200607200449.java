import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

import javax.swing.tree.TreeNode;

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
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return new LinkedList<Integer>();
        
        List<Integer> ans = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<>();
        List<Boolean> is_Visited = new LinkedList<>();
        ans.add(root);

        while(!ans.isEmpty()){
            TreeNode cur_Node = stack.peek();
            if((cur_Node.left == null && cur_Node.right == null) || is_Visited.get(ans.size())){
                stack.pop();
                ans.add(cur_Node.val);
            }

            is_Visited.set(ans.size(), true);
            if(cur_Node.left != null) stack.add(cur_Node.left);
            if(cur_Node.right != null) stack.add(cur_Node.right);
        }
        
        return ans;
    }
}