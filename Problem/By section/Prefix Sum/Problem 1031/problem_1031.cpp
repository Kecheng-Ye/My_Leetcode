#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        const int n = nums.size();
        vector<int> prefixSumMax(n, 0), suffixSumMax(n, 0);

        int temp = 0;
        int i = 0, j = 0;

        // prefixSumMax[i] = max(all sliding window with firstLen on nums[:i])
        while (j < n) {
            temp += nums[j++];
            
            if (j - i < firstLen) continue;

            prefixSumMax[j - 1] = max(((j - 2) < 0 ? 0 : prefixSumMax[j - 2]) ,temp);
            temp -= nums[i++];
        }

        temp = 0;
        i = n - 1, j = n - 1;

        // suffixSumMax[i] = max(all sliding window with firstLen on nums[i:])
        while (j >= 0) {
            temp += nums[j--];
            
            if (i - j < firstLen) continue;

            suffixSumMax[j + 1] = max(temp, (j + 2 >= n) ? 0 : suffixSumMax[j + 2]);
            temp -= nums[i--];
        }   

        temp = 0;
        i = 0, j = 0;
        int result = 0;

        while (j < n) {
            temp += nums[j++];
            
            if (j - i < secondLen) continue;

            const int currMax = temp + max(
                i == 0 ? 0 : prefixSumMax[i - 1], 
                j == n ? 0 : suffixSumMax[j]
            );
            temp -= nums[i++];
            result = max(currMax, result);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}