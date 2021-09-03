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
    HashMap<TreeNode, Integer> memo = new HashMap<>();

    public int rob(TreeNode root) {
        if(root == null) return 0;

        if(memo.containsKey(root)) return memo.get(root);

        int rob_this = root.val + 
                       (root.left == null ? 0 : rob(root.left.left) + rob(root.left.right)) +
                       (root.right == null ? 0 : rob(root.right.left) + rob(root.right.right));
        
        int not_rob = rob(root.left) + rob(root.right);

        memo.put(root, Math.max(rob_this, not_rob));
        return Math.max(rob_this, not_rob);
    }

}