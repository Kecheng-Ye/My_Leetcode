#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // swap[i]: the minimum number of swaps that can make nums1[0:i] and nums2[0:i] strictly increasing by swaping num1[i] and num2[i]
    // keep[i]: the minimum number of swaps that can make nums1[0:i] and nums2[0:i] strictly increasing by keeping num1[i] and num2[i]
    // swap[i] = min(swap[i - 1] + 1(if num1[i] > num1[i - 1] and num2[i] > num2[i - 1]), keep[i - 1] + 1(if num1[i] > num2[i - 1] and num2[i] > num1[i - 1]))
    // keep[i] = min(keep[i - 1](if num1[i] > num1[i - 1] and num2[i] > num2[i - 1]), swap[i - 1](if num1[i] > num2[i - 1] and num2[i] > num1[i - 1]))
    // Time: O(n), Space: O(1)
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int swap = 0, keep = 0, prev_swap = 1, prev_keep = 0; // prev_swap should initialized as 1 because you have to use 1 swap to change the nums1[0] and nums2[0]
        int n = nums1.size();
        
        for(int i = 1; i < n; i++) {
            swap = INT_MAX; // since we are using min operation, both swap and keep should be initialized as MAX value, or some of them may go wrong
            keep = INT_MAX;
            
            if(nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                swap = prev_swap + 1;
                keep = prev_keep;
            }
            
            if(nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                swap = min(swap, prev_keep + 1);
                keep = min(keep, prev_swap);
            }
            
            prev_swap = swap;
            prev_keep = keep;
        }
        
        
        return min(swap, keep);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}