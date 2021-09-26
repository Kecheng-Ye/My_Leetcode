#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> record;
        int sum = 0;
        int max_len = 0;
        
        for(int i = 0; i < n; i++) {
            int val = nums[i] ? 1 : -1;
            sum += val;
            
            if(!sum) {
                max_len = i + 1;
            }
            
            if(record.count(sum)) {
                max_len = max(max_len, i - record[sum]);
            }else{
                record[sum] = i;
            }
            
        }
        
        return max_len;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}