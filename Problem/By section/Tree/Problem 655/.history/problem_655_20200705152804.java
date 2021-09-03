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
    public String toString(){
        return String.valueOf(val);
    }
}

class Solution {
    public List<List<String>> printTree(TreeNode root) {
        if(root == null) return null;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<List<TreeNode>> each_layer = new LinkedList<>();
        
        while(!queue.isEmpty()){
            int level_size = each_layer.get(each_layer.size() - 1).size();
            List<TreeNode> new_layer = new LinkedList<>();
            for(int i = 0; i < level_size; i++){
                if(each_layer.get(each_layer.size() - 1).get(i) == null){
                    new_layer.add(null);
                    new_layer.add(null);
                }else{
                    new_layer.add(each_layer.get(each_layer.size() - 1).get(i).left);
                    new_layer.add(each_layer.get(each_layer.size() - 1).get(i).right);
                }
            }

            each_layer.add(new_layer);
        }
        
        System.out.println(each_layer);

        List<List<String>> ans = new LinkedList<>();
        int size = 2 * each_layer.get(each_layer.size() - 1).size() - 1;

        for(int i = 0; i < each_layer.size() ; i++){
            ans.add(layer_repr(each_layer.get(i), size));
        }

        return ans;
    }


    public List<String> layer_repr(List<TreeNode> layer, int size){
        if(layer.size() == 1 ){
            List<String> temp = new LinkedList<>();
            for(int i = 0; i < size/2; i++){
                temp.add("");
            }
            temp.add(node_repr(layer.get(0)));
            for(int i = 0; i < size/2; i++){
                temp.add("");
            }
        }

        List<String> left = layer_repr(layer.subList(0, layer.size()/2), size/2);
        List<String> right = layer_repr(layer.subList(layer.size()/2, layer.size()), size/2);
        
        List<String> ans = new LinkedList<>();
        ans.addAll(left);
        ans.add("");
        ans.addAll(right);
        
        return ans;
    }

    private String node_repr(TreeNode node){
        return (node == null) ? "" : String.valueOf(node.val);
    }
}


public class problem_655{
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.right = new TreeNode(4);
        root.left.left = new TreeNode(0);

        Solution sol = new Solution();
        sol.printTree(root);
    }
}