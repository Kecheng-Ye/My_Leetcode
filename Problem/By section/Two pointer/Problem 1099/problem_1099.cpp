#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int twoSumLessThanK(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1;
        
        sort(nums.begin(), nums.end());
        
        int result = INT_MIN;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(nums[i] + nums[j] < k) {
                result = max(result, sum);
                i++;
            }else{
                j--;
            }
        }
        
        return result == INT_MIN ? -1 : result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}