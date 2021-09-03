import java.util.*;
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                return arr1[0] - arr2[0];
            }
        });
        
        int i = 0;
        int ans = 1;
        int upper_bound = points[i][1];
        
        while(i + 1 < points.length){
            if(points[++ i][0] > upper_bound){
                ans ++;
                upper_bound = points[i][1]
            }
        }
        
        return ans
    }
}