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
        
        List<List<String>> ans = new LinkedList<>();
        int depth = each_layer.size();

        for(int i = each_layer.size() - 1; i >= 0; i--){

        }

        return null;
    }


    public List<String> layer_repr(List<TreeNode> layer, int size){
        if(layer.size() == 1 ){
            if(size == 1){
                List<String> temp = new LinkedList<>();
                temp.add(node_repr(layer.get(0)));
                return temp;
            }else if(size == 3){
                List<String> temp = new LinkedList<>();
                temp.add("");
                temp.add(node_repr(layer.get(0)));
                temp.add("");
                return temp;
            }
        }

        List<String> left = layer_repr(layer.subList(0, layer.size()/2), size/2);
        List<String> right = layer_repr(layer.subList(layer.size()/2, layer.size()), size/2);
        return null;
    }

    private String node_repr(TreeNode node){
        return (node == null) ? "" : String.valueOf(node.val);
    }
}