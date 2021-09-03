
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        
        return isSymmetricHelper(root.left, root.right);
    }
    
    private boolean isSymmetricHelper(TreeNode left, TreeNode right){
        if(left == null && right == null){
            return true;
        }else if(left == null || right == null){
            return false;
        }else{
            if(left.val != right.val) return false;
            
            return isSymmetricHelper(left.right, right.left) &&
                   isSymmetricHelper(right.right, left.left);
        }
    }
}

