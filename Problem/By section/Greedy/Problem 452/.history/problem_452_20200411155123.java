import java.util.*;
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0) return 0;
        
        Arrays.sort(points, new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                return (arr1[1] == arr2[1]) ? arr1[0] - arr2[0] : arr1[1] - arr2[1];
            }
        });
        
        
        int i = 0;
        int ans = 1;
        int upper_bound = points[i][1];
        
        while(i + 1 < points.length){
            if(points[++ i][0] > upper_bound){
                ans ++;
                upper_bound = points[i][1];
            }
        }
        
        return ans;
    }

    public void print(int[][] points){
        for(int[] arr : points){
            System.out.print("[" + print(arr) + "] ");
        }
        System.out.println();
    }

    public String print(int[] arr){
        String ans = "[";
        for(int i : arr){
            ans += i + " ";
        }
        return ans + "]";
    }
}