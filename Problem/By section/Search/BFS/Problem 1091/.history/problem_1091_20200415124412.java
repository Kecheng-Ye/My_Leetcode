import java.util.*;
class Solution {
    private int[][] direcrion = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1 ,1}, {-1, 0}};
    
    // Time: O(n), Space: O(n)
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid.length == 0 || grid[0][0] == 1){
            return -1;
        }
        
        // Use BFS
        boolean[][] isVisited = new boolean[grid.length][grid[0].length];
        
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] != 0){
                    isVisited[i][j] = true;
                }
            }
        }
        
        int step = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0,0});
        
        // as long as the queue is not empty
        while(queue.size() != 0){
            int size = queue.size();
            // we peek each aviliable state
            for(int i = 0; i < size; i++){
                int[] curr_local = queue.poll();
                if(curr_local[0] == grid.length - 1 && curr_local[1] == grid[0].length - 1){
                        return step;
                }
                // do action on this state
                for(int[] action : direcrion){
                    int temp_x = curr_local[0] + action[0];
                    int temp_y = curr_local[1] + action[1];
                    if(temp_x > grid.length - 1 || temp_x < 0 || temp_y > grid[0].length - 1 || temp_y < 0) continue;
                    int[] new_local = new int[]{temp_x, temp_y};          
                    // as long as we have not been in this state before
                    // we will remember this new state
                    // and add this state back to queue
                    if(isVisited[new_local[0]][new_local[1]]){
                        continue;
                    }else{
                        queue.add(new_local);
                        isVisited[new_local[0]][new_local[1]] = true;   
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    
}