#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int characterReplacement(string s, int k) {
        const int n = s.size();
        int left = 0, right = 0;
        vector<int> record(26, 0);
        int currMax = INT_MIN;
        int maxF = 0;

        while (right < n) {
            record[(s[right] - 'A')]++;
            // maxF = *max_element(record.begin(), record.end());
            // tricky part: we don't need to find maxF across the cnt every time
            // for the condition: window size - maxF <= k
            // the window size will have the max value when maxF reaches its max value
            // so we dont need to find maxF every time
            maxF = max(record[(s[right] - 'A')], maxF);
            right++;
        
            while (right - left - maxF > k) {
                record[(s[left++] - 'A')]--;
                // maxF = *max_element(record.begin(), record.end());
            }

            currMax = max(currMax, right - left);
        }

        return currMax;
    }
};


int main(int argc, char** argv) {
    Solution s;

    return 0;
}
