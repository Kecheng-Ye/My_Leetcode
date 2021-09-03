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
    // Time: O(n), Space: O(1)
    public boolean isBalanced(TreeNode root) {
        MaxDepth(root);
        return ans;
    }

    // global variable for dynmaically updating the ans
    private boolean ans = true;

    // for each node in the tree
    // we will only need to search for once 
    private int MaxDepth(TreeNode root){
        if(root == null) return 0;
        // get the left and right branch depth
        int left = MaxDepth(root.left);
        int right = MaxDepth(root.right);
        // update the current subtree isBalanced condition
        if(Math.abs(left - right) > 1) ans = false;
        // return the depth of this node
        return Math.max(left, right) + 1;
    }
}
