#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;

        int left = 0, right = 0, result = 0;
        vector<int> record(256, 0);

        while(right < n) {
            char c1 = s[right];
            record[c1]++;
            right++;

            while (record[c1] > 1) {
                char c2 = s[left];
                record[c2]--;
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
