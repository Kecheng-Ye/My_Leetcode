#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(2^n), Space: O(n)
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;

        for (int i = 1; i <= 9; i++) {
            backtrack(result, n - 1, k, i);
        }

        return result;
    }

    void backtrack(vector<int>& result, int n, int k, int number) {
        if (n == 0) {
            result.push_back(number);
            return;
        }

        int lastDigit = number % 10;

        if (lastDigit - k >= 0) {
            backtrack(result, n - 1, k, number * 10 + (lastDigit - k));
        }

        if (k != 0 && lastDigit + k < 10) {
            backtrack(result, n - 1, k, number * 10 + (lastDigit + k));
        }
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
