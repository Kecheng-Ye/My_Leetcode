#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = prefix_max_left
    // Time: O(n), Space: O(n)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if(!n) return 0;
        
    //     vector<int> dp_l(n, 0);
    //     dp_l[0] = height[0];
        
    //     vector<int> dp_r(n, 0);
    //     dp_r[n - 1] = height[n - 1];
        
    //     for(int i = 1; i < n; i++) {
    //         dp_l[i] = max(height[i], dp_l[i - 1]);
    //     }
        
    //     for(int j = n - 2; j >= 0; j--) {
    //         dp_r[j] = max(height[j], dp_r[j + 1]);
    //     }
        
    //     int result = 0;
        
    //     for(int i = 0; i < n; i++) {
    //         result += min(dp_l[i], dp_r[i]) - height[i];
    //     }
        
    //     return result;
    // }
    
    // Time: O(n), Space: O(1)
    int trap(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        
        int left = 0, max_left = height[left];
        int right = n - 1, max_right = height[right];
        int result = 0;
        
        while(left < right) {
            if(max_left < max_right) {
                result += max_left - height[left];
                max_left = max(max_left, height[++left]);
            }else{
                result += max_right - height[right];
                max_right = max(max_right, height[--right]);
            }
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}