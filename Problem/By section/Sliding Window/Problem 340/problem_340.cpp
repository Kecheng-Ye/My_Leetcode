#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int numOfDistinctChar = 0;
        int result = 0;
        vector<int> record(256, 0);

        while (right < n) {
            char c1 = s[right];
            record[c1] ++;
            if (record[c1] == 1) {
                numOfDistinctChar ++;
            }
            right++;

            while (numOfDistinctChar > k) {
                char c2 = s[left];
                record[c2] --;
                if (record[c2] == 0) {
                    numOfDistinctChar --;
                }
                left++;
            }

            result = max(result, right - left);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
