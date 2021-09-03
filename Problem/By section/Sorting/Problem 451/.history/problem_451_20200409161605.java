import java.util.*;
class Solution {
    public String frequencySort(String s) {
        Hashtable<Character, Integer> frequency_map = new  Hashtable<Character, Integer>();
        char[] arr = s.toCharArray();
        
        for(char i : arr){
            frequency_map.put(i, frequency_map.getOrDefault(i, 0) + 1);
        }
        
        List<Character>[] buckets = new ArrayList[s.length() + 1];
        
        for(char key : frequency_map.keySet()){
            int frequency = frequency_map.get(key);
            if(buckets[frequency] == null){
                buckets[frequency] = new ArrayList<>(); 
            }
            
            buckets[frequency].add(key);
        }
        
        StringBuilder ans = new StringBuilder();
        
        for(int i = buckets.length - 1; i >= 0; i --){
            if(buckets[i] == null) continue;
            
            for(char a : buckets[i]){
                for(int j = 0; j < i; j++){
                    ans.append(a);
                }
            }
        }
        
        return ans.toString();
    }
}