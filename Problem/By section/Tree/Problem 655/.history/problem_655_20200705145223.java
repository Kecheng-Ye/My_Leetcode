import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<List<String>> printTree(TreeNode root) {
        if(root == null) return null;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<List<TreeNode>> each_layer = new LinkedList<>();
        
        while(!queue.isEmpty()){
            int level_size = each_layer.get
            
            for(int i = 0; i < level_size, i++){
                
            }
        }
    }
}