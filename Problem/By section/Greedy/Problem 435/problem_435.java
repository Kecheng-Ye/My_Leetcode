import java.util.*;

class Solution {
    // Use Greedy Algothrim
    // Time: O(nlog(n)), Space: O(1)
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 0) return 0;
        
        // Important!!!
        // How to define a comparator in order to do the sorting
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] arr1, int[] arr2){
                return arr1[1] - arr2[1];
            }
        });
        
        // Answer stands for the length of the longest legal interval
        // As long as the intervals array has length >= 1
        // we can at least have the head interval included in our final interval
        int ans = 1;
        int i = 0;
        int last_end = intervals[i][1];
        
        // iterate intervals array and include whatever the interval is leagal
        while(i + 1 < intervals.length ){
            if(intervals[++ i][0] >= last_end){
                ans ++;
                last_end = intervals[i][1];
            }
        }
        
        return intervals.length - ans;
    }
}