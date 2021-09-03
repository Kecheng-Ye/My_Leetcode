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
    public List<Double> averageOfLevels(TreeNode root) {
        if(root == null) return null;
        
        List<Double> ans = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        while(!queue.isEmpty()){
            double sum = 0;
            // important, the size of a level is the size of the whole queue 
            // after poping all the stuff from the previous layer
            int this_level_nodes = queue.size();
            for(int i = 0; i < this_level_nodes; i++){
                TreeNode cur_node = queue.poll();
                sum += cur_node.val;
                if(cur_node.left != null){
                    queue.add(cur_node.left);
                }
                
                if(cur_node.right != null){
                    queue.add(cur_node.right);
                }
            }
            ans.add(sum/this_level_nodes);
        }
        
        return ans;
    }
}