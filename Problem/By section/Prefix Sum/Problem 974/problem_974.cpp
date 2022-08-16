#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        vector<int> records(k, 0);
        int pre_sum = 0;

        for (const int& i : nums) {
            pre_sum += i;
            int residual = pre_sum % k;
            if (residual < 0) {
                residual += k;
            }

            if (residual == 0) {
                result += 1;
            }

            result += records[residual];
            records[residual] += 1;
        }

        return result;
    }
};


int main(int argc, char** argv) {
    Solution s;

    return 0;
}
