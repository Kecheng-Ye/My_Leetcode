#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn + n^2), Space: O(n)
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result;
        int min_diff = INT_MAX;
        
        
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return target;
                
                if(abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    result = sum;
                }
            
                if(sum > target) {
                    right--;
                }else{
                    left++;
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