#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int result = INT_MIN;
//         int curr_product = 1;
//         const int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             curr_product *= nums[i];
//             // need to first update result then reset to 1
//             // since we cannot have 1 as the result
//             result = max(curr_product, result);
//             if (curr_product == 0) {
//                 curr_product = 1;
//             } 
//         }

//         curr_product = 1;

//         for (int i = n - 1; i >= 0; i--) {
//             curr_product *= nums[i];
//             result = max(curr_product, result);
//             if (curr_product == 0) {
//                 curr_product = 1;
//             }
//         }

//         return result;
//     }
// };

#define MAX 0
#define MIN 1
#define CURR 2

class Solution {
public:
    // Time: O(n), Space: O(1)
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0; 

        int maxProduct = nums[0];
        vector<int> record(3, maxProduct);

        for (int i = 1; i < n; i++) {
            const int curr = nums[i];
            record[CURR] = curr;
            record[MAX] *= curr;
            record[MIN] *= curr;

            const int currMax = *max_element(record.begin(), record.end());
            const int currMin = *min_element(record.begin(), record.end());
            record[MAX] = currMax;
            record[MIN] = currMin;

            maxProduct = max(maxProduct, record[MAX]);
        }

        return maxProduct;
    }
};

int main(int argc, char **argv) {
    Solution s;

    return 0;
}
