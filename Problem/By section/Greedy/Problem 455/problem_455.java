import java.util.*;

class Solution {
    // Time: O(nlog(n)) or O(n + m), Space : O(1)
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        // two pointer
        int i = 0;
        int j = 0;
        int ans = 0;
        
        while(i < g.length && j < s.length){
            // we will assign the current least size cookie to the children will least content value
            // if feasible
            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            }else{
                j ++;
            }
        }
        
        return ans;
    }
}