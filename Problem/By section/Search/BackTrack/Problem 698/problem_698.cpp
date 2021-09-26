#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n!), Space: O(1);
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        sort(nums.rbegin(), nums.rend());  
        return backtrack(nums, sum / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums, int sum, int cur_sum, int is_visited, int k) {     
        if(k == 0) {
            return is_visited == (1 << nums.size()) - 1;
        }else{
            for(int i = 0; i < nums.size(); i++) {
                if(is_visited & (1 << i)) {
                    continue;
                }
                
                if(i > 0 && nums[i] == nums[i - 1] && !(is_visited & (1 << (i - 1)))) {
                    continue;
                }
                
                is_visited |= (1 << i);
                cur_sum += nums[i];
                if(cur_sum > sum) break;
                
                if(cur_sum == sum) {
                    return backtrack(nums, sum, 0, is_visited, k - 1);
                }else{
                    if(backtrack(nums, sum, cur_sum, is_visited, k)) {
                        return true;
                    }   
                }
                
                cur_sum -= nums[i];
                is_visited ^= (1 << i);
                
            }
            return false;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}