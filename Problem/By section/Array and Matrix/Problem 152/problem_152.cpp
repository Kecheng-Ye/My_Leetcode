#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int curr_product = 1;
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            curr_product *= nums[i];
            // need to first update result then reset to 1
            // since we cannot have 1 as the result
            result = max(curr_product, result);
            if (curr_product == 0) {
                curr_product = 1;
            } 
        }

        curr_product = 1;

        for (int i = n - 1; i >= 0; i--) {
            curr_product *= nums[i];
            result = max(curr_product, result);
            if (curr_product == 0) {
                curr_product = 1;
            }
        }

        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;

    return 0;
}
