
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
        return 0;
    }

    private void helper(TreeNode root, int level){
        if(root == null) return;

        ans[level % 2] += root.val;


    }

}