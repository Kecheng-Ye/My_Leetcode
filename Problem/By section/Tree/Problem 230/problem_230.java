class Solution {
    int ans;
    int cur_k = 0;
    // Time: O(n), Space : O(n)
    public int kthSmallest(TreeNode root, int k) {
        inorder(root, k);
        return ans;
    }
    
    // inorder traversal
    public void inorder(TreeNode root, int k){
        if(root == null) return;
        
        inorder(root.left, k);
        
        cur_k ++;
        if(cur_k == k){
            ans = root.val;
            return;
        }
        
        inorder(root.right, k);
    }
}