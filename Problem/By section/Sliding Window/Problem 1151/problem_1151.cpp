#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // sliding window, always keep a window with size `ones`
    // and check how many zeros in this window
    // Time: O(n), Space: O(1)
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(const int i : data) {
            if (i) ones += 1;
        }

        int n = data.size();
        int left = 0, right = 0;
        int numberOfZeros = 0;
        int result = INT_MAX;

        while (right < n) {
            int num1 = data[right];
            if (!num1) numberOfZeros++;
            right++;

            if (right - left == ones) {
                int num2 = data[left];
                result = min(result, numberOfZeros);
                if (!num2) numberOfZeros--;
                left++;
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
