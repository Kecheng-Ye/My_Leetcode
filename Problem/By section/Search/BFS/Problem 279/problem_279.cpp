#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n * sqrt(n)), Space: O(sqrt(n))
    int numSquares(int n) {
        if (isPerfectSqr(n)) {
            return 1;
        }

        const vector<int> sqrNums = perfectSqrs(n);
        queue<int> q;
        vector<bool> isVisited(n, false);
        int step = 0;

        q.push(n);

        while (!q.empty()) {
            int levelSize = q.size();
            step++;

            while (levelSize--) {
                const int curr = q.front(); q.pop();

                if (curr == 0) {
                    return step - 1;
                }

                for (const int candidate : sqrNums) {
                    if (candidate > curr) break;

                    const int left = curr - candidate;
                    if (!isVisited[left]) {
                        isVisited[left] = true;
                        q.push(left);
                    }
                }
            }
        }

        return -1;

    }

    bool isPerfectSqr(const int num) {
        const int _root = (int)sqrt((double) num);
        return ((_root * _root) == num) || (((_root + 1) * (_root + 1)) == num);
    }

    vector<int> perfectSqrs(int limit) {
        int curr = 1;
        int diff = 3;
        int step = 2;

        vector<int> result;

        while (curr < limit) {
            result.push_back(curr);
            curr += diff;
            diff += step;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numSquares(12) << endl;
    
    // bool test[100];

    // cout << test[0] << " " << test[99] << endl;
    
    return 0;
}