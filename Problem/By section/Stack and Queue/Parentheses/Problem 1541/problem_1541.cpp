#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int minInsertions(string s) {
        int res = 0, right = 0;
        for (char &c: s) {
            if (c == '(') {
                if (right % 2 > 0) {
                    right--;
                    res++;
                }
                right += 2;
            } else {
                right--;
                if (right < 0) {
                    right += 2;
                    res++;
                }
            }
        }
        return right + res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}