import java.util.*;
class Solution {
    // Time: O(n), Space: O(26/128)
    public List<Integer> partitionLabels(String S) {
        HashMap<Character, Integer> map = new HashMap<>();
        
        char[] arr = S.toCharArray();
        for(int i = 0; i < S.length(); i++){
            map.put(arr[i], i);
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        int last_occur = -1;
        int record = 0;
        
        for(int i = 0; i < S.length(); i++){
            char temp = arr[i];  
            last_occur = Math.max(last_occur, map.get(temp));
            record ++;
            if(i == last_occur){
                ans.add(record);
                record = 0;
                
            }
        }

        return ans;
    }
}