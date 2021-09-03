import java.util.*;

class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Time: O(w(1) * w(n - 1) + w(2) * w(n - 2) + .... + w(n - 1) * w(1))
    // Space: Same
    public List<TreeNode> generateTrees(int n) {
        if(n <= 0) return new ArrayList<TreeNode>();

        return helper(1, n);
    }
    
    // Basic idea:
    // we know a bts tree has its root and its range
    // we will itearte all possible roots within its range and make it me the subtree of this bts tree
    // then the recursion will do its job for us 
    public List<TreeNode> helper(int start, int end){
        // if the start > end
        // no bts tree can construct
        if(start > end){
            return Arrays.asList((TreeNode) null);
        }else{
            List<TreeNode> curr_ans = new ArrayList<>();
            for(int i = start; i <= end; i ++){
                // the left tree range of this root i is [start, i - 1] 
                List<TreeNode> left = helper(start, i - 1);
                // the right tree range of this root i is [i + 1, end] 
                List<TreeNode> right = helper(i + 1, end);
                // concatenate the left and right tree with root 
                // form the new list
                for(TreeNode l : left){
                    for(TreeNode r : right){
                        TreeNode temp = new TreeNode(i);
                        temp.left = l;
                        temp.right = r;
                        curr_ans.add(temp);
                    }
                }
            }

            return curr_ans;
        }
    }
}