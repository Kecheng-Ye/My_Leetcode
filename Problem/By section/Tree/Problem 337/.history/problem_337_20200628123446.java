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
    int[] ans = new int[2];

    public int rob(TreeNode root) {
        helper(root, 0);

        return Math.max(ans[0], ans[1]);
    }

    private void helper(TreeNode root, int level){
        if(root == null) return;

        ans[level % 2] += root.val;

        helper(root.left, level + 1);
        helper(root.right, level + 1);
    }

}