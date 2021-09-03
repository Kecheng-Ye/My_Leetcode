import java.util.*;
class Solution {
    // Time: O(n), Space: O(26/128)
    public List<Integer> partitionLabels(String S) {
        // use Hashmap to contain the last index of each character in 'S'
        // reduce run time from O(n^2) to O(n)
        HashMap<Character, Integer> map = new HashMap<>();
        
        char[] arr = S.toCharArray();
        for(int i = 0; i < S.length(); i++){
            map.put(arr[i], i);
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        int last_occur = -1;
        int record = 0;
        
        // 'last_occur' means the biggest index of last occured character in the current substring
        // if the iteration pointer meet the 'last_occur'
        // meaning it has already complete a partition substring
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