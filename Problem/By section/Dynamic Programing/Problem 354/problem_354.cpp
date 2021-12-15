#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    // for a valid envelop sequence, we have to make sure that for every e_i and e_(i + 1), 
    // both dimension of e_(i + 1) is bigger than e_i
    // if we split this two dimensions
    // we can see that each dimension is a strickly increasing sequence
    // so we will first sort the array by its first dimension in increasing order
    // also by its second dimension in decreasing order to fullfill the requirement that thoes envelops with same width can only have one in the final sequence
    // Time: O(nlogn), Space: O(n) 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n <= 1) return n;
        
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> second_dim;
        for(const auto& env : envelopes) {
            second_dim.push_back(env[1]);
        }
        
        return LIS(second_dim);
        
    }
    
    // Same as LC-300
    int LIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        vector<int> dp;
        
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end()) {
                dp.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        
        return dp.size();
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}