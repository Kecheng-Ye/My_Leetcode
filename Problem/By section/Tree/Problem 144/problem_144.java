import java.util.*;


class Solution {
    
//     public List<Integer> preorderTraversal(TreeNode root) {
//         List<Integer> ans = new LinkedList<>();
//         dfs(root, ans);
//         return ans;
//     }
    
//     public void dfs(TreeNode root, List<Integer> ans){
//         if(root == null) return;
        
//         ans.add(root.val);
//         dfs(root.left, ans);
//         dfs(root.right, ans);
//     }
    
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null) return new LinkedList<>();;

        List<Integer> ans = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);

        while(!stack.isEmpty()){
            TreeNode cur_Node = stack.pop();
            ans.add(cur_Node.val);
            
            if(cur_Node.right != null) stack.add(cur_Node.right);
            if(cur_Node.left != null) stack.add(cur_Node.left);
        }

        return ans;
    }
}