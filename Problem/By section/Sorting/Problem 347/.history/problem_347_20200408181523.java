import java.util.*;
class Solution {
    // Time: O(n), Space: O(n)
    public List<Integer> topKFrequent(int[] nums, int k) {
        // The frequency map for recording the frequency of each element in nums
        HashMap<Integer, Integer> frequency_map = new HashMap<>();
        
        for(int i : nums){
            frequency_map.put(i, frequency_map.getOrDefault(i, 0) + 1);
        }
        
        // The buckets array storing the elements whoes frequency is exactly
        // i in the ith position
        // maybe one frequency contains many number
        // so it is a ArrayList array
        ArrayList<Integer>[] buckets = new ArrayList[nums.length + 1];
        
        for(int i : frequency_map.keySet()){
            int frequency = frequency_map.get(i);
            if(buckets[frequency] == null) buckets[frequency] = new ArrayList<Integer>();
            
            buckets[frequency].add(i);
        }
        
        // the answer list
        List<Integer> ans = new ArrayList<>();
        
        // iterate from the end of the buckets(most frequent --> least frequent)
        // if we have include k numbers, meaning we have record kth number which occurs most frequently
        // we halt the iteration and return the answer
        for(int i = buckets.length - 1; i >= 0 && k > 0; i --){
            if(buckets[i] == null) continue;
            
            if(buckets[i].size() <= k){
                ans.addAll(buckets[i]);
                k -= buckets[i].size();
            }else{
                ans.addAll(buckets[i].subList(0, buckets[i].size() - k));
            }
        }
        
        return ans;
    }
}