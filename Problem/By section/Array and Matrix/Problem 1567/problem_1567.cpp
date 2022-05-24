#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        
        int start = 0, first_neg = -1, count = 0;
        int cur = 0, result = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                cur = 0; 
                count = 0;
                first_neg = -1;
                start = i + 1;
            }else if(nums[i] > 0){
                cur += 1;
            }else{
                count++;
                if(first_neg == -1) {
                    cur = 0;
                    first_neg = i;
                }else{
                    if(count % 2 == 0) {
                        cur = i - start + 1;
                    }else{
                        cur = i - first_neg;
                    }
                }
            }
            
            result = max(result, cur);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}