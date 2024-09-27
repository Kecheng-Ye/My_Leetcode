#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(logn)
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        const function<void(const int)> dfs = [&](const int start) {
            if (start > n) return;

            result.push_back(start);

            for (int i = 0; i < 10; i++) {
                const int nextNum = start * 10 + i;

                if (nextNum <= n) {
                    dfs(nextNum);
                } else {
                    break;
                }
            }
        };

        for (int i = 1; i < 10; i++) {
            dfs(i);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}