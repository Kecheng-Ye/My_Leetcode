import java.util.*;
class Solution {
    private final int[][] direction = {{-1,0}, {1,0}, {0,1}, {0, -1}};
    
    // Time: O(w * h), Space: O(w * h)
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        if(matrix.length == 0) return (new ArrayList<List<Integer>>());
        
        // dfs on each ocean and if a place can be reached by both ocean
        // add to the ans
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        boolean[][] Atlantic = new boolean[matrix.length][matrix[0].length];
        boolean[][] Pacific = new boolean[matrix.length][matrix[0].length];
        
        for(int i = 0; i < matrix.length; i ++){
            DFS(matrix, i, 0, Pacific);
            DFS(matrix, i, matrix[0].length - 1, Atlantic);
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
            int new_x = i + action[0];
            int new_y = j + action[1];
            
            if(new_x < 0 || new_x > matrix.length - 1 || 
               new_y < 0 || new_y > matrix[0].length - 1 || 
               is_Visited[new_x][new_y] || 
               matrix[new_x][new_y] < matrix[i][j]){
                   
                continue;
            }
            
            DFS(matrix, new_x, new_y, is_Visited);

        }
    }
}


public class problem_417{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] test = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        sol.pacificAtlantic(test);
    }
}