import java.util.*;

class Solution {
    // Use Greedy Algothrim
    // Time: O(nlog(n)), Space: O(1)
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 0) return 0;
        
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                return arr1[1] - arr2[1];
            }
        });
            
        int ans = 1;
        int i = 0;
        int last_end = intervals[i][1];
        
        while(i + 1 < intervals.length ){
            if(intervals[++ i][0] >= last_end){
                ans ++;
                last_end = intervals[i][1];
            }
        }
        
        return intervals.length - ans;
    }
}