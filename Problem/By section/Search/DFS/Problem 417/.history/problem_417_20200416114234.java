import java.util.*;
class Solution {
    private final int[][] direction = {{-1,0}, {1,0}, {0,1}, {0, -1}};
        
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        if(matrix.length == 0) return (new ArrayList<List<Integer>>());
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        boolean[][] Atlantic = new boolean[matrix.length][matrix[0].length];
        boolean[][] Pacific = new boolean[matrix.length][matrix[0].length];
        
        for(int i = 0; i < matrix.length; i ++){
            DFS(matrix, i, 0, Pacific);
            DFS(matrix, i, matrix[0].length, Atlantic);
        }
        
        for(int i = 0; i < matrix[0].length; i++){
            DFS(matrix, 0, i, Pacific);
            DFS(matrix, matrix.length - 1, i, Atlantic);
        }
        
        for(int i = 0; i < matrix.length; i ++){
            for(int j = 0; j < matrix[0].length; j++){
                if(Atlantic[i][j] && Pacific[i][j]){
                    ans.add(Arrays.asList(i,j));
                }
            }
        }
        
        return ans;
    }
    
    public void DFS(int[][] matrix, int i, int j, boolean[][] is_Visited){
        is_Visited[i][j] = true;
        for(int[] action : direction){
            int new_y = i + action[0];
            int new_x = j + action[1];
            
            if(new_x < 0 || new_y > matrix.length - 1 || new_x < 0 || new_x > matrix[0].length - 1 || is_Visited[new_y][new_x] || matrix[new_y][new_x] < matrix[i][j]){
                continue;
            }
            
            DFS(matrix, new_y, new_x, is_Visited);

        }
    }
}