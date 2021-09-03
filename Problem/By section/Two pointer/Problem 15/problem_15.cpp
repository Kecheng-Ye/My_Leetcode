#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        
        for(int k = 0; k < n; k++) {
            if(k > 0 && nums[k] == nums[k - 1]) continue;
            
            int i = k + 1, j = n - 1;
            int target = -1 * nums[k];
            
            while(i < j) {
                if(nums[i] + nums[j] == target) {
                    result.push_back({nums[i++], nums[j--], nums[k]});
                    
                    while(i < j && nums[i] == nums[i - 1]) i++;
                    while(i < j && nums[j] == nums[j + 1]) j--;
                }else if(nums[i] + nums[j] < target) {
                    i++;
                }else if(nums[i] + nums[j] > target) {
                    j--;
                }
            }
        }
        
        return result;
    }
    
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}