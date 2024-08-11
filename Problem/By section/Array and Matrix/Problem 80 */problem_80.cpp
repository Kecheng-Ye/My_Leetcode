#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 2) return n;
        
    //     unordered_map<int, int> record;
    //     for(const auto& i : nums) {
    //         record[i]++;
    //     }
        
    //     int result = 0;
    //     for(int i = 0; i < n; i++) {
    //         int len = min(record[nums[i]], 2);
            
    //         for(int j = i; j < i + len; j++) {
    //             nums[result++] = nums[i];
    //         }
            
    //         i += record[nums[i]] - 1;
    //     }
        
    //     return result;
        
    // }
    
    // Two ptrs
    // Time: O(n), Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        
        int result = 0;
        int start = 0, end = 0;
        int cur = nums[start];
        
        while(end < n) {
            if(nums[end] == cur) {
                if(end - start < 2) {
                    nums[result++] = cur;
                }
            }else{
                cur = nums[end];
                start = end;
                
                nums[result++] = cur;
            }
            
            end++;
            
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}