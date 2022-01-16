#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int result = 0;
        unordered_map<int, int> record;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) sum++;
            
            if(sum == k) {
                result++;
            }
            result += record[sum - k];   
            
            record[sum]++;
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}