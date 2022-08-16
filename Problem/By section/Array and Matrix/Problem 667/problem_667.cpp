#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // [1, n, 2, n - 2, 3, ...] will result in a n - 1 distinct diff
    // Time: O(n), Space: O(1)
    vector<int> constructArray(int n, int k) {
        vector<int> result(n, 0);
        int c = 0;

        for (int v = 1; v < n-k; v++) { // first produce acc order of number
            result[c++] = v;
        }

        for (int i = 0; i <= k; i++) { // after n - k number, we have to produce alternating serise to reach [1, n, 2, n - 2]
            result[c++] = (i%2 == 0) ? (n-k + i/2) : (n - i/2);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
