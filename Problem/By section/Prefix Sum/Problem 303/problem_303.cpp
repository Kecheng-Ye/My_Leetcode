#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> array;
    vector<int> dp;

    NumArray(vector<int>& nums) {
        int size = nums.size();

        array = vector<int>(nums);
        dp = vector<int>(size + 1, 0);
        int result = 0;

        for(int i = 1; i <= size; i ++) {
            result += array[i - 1];
            dp[i] = result;
        }
    }
    
    // Time: O(1), Space: O(n)
    int sumRange(int left, int right) {
        return(dp[right + 1] - dp[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main(int argc, char** argv) {

    return 0;
}