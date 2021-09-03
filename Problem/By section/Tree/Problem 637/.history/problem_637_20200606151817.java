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
import java.util.*;

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        if(root == null) return null;
        
        List<Double> ans = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int this_level_nodes = 1;
        
        while(!queue.isEmpty()){
            int sum = 0;
            int next_level_node = 0;
            for(int i = 0; i < this_level_nodes; i++){
                TreeNode cur_node = queue.poll();
                sum += cur_node.val;
                next_level_node += (cur_node.left == null) ? 0 : 1;
                next_level_node += (cur_node.right == null) ? 0 : 1;
            }
            ans.add((double)(sum/this_level_nodes));
            this_level_nodes = next_level_node;
        }
        
        return ans;
    }
}