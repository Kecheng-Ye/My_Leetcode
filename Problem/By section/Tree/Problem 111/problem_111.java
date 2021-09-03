import java.util.;

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
    // Time: O(n), Space: O(n)
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        // important here, because we want to find the leaf with min depth, so we have to search to the end
        if(root.left == null || root.right == null) return 1 + Math.max(minDepth(root.left), minDepth(root.right));
        
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }
}