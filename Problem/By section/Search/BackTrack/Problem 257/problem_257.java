import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Time: O(tree size), Space: O(all combination)
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        
        if(root == null) return ans;
        
        backtrack(root, ans, "");
        
        return ans;
    }
    
    
    public void backtrack(TreeNode node, List<String> ans, String current){
        // fail condition
        if(node == null) return;
        
        // success condition
        if(node.left == null && node.right == null){
            ans.add(current + String.valueOf(node.val));
            return;
        }
        
        //updating
        current += String.valueOf(node.val) + "->";
        backtrack(node.left, ans, current);
        backtrack(node.right, ans, current);
    }
}