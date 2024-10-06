#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    string reorganizeString(string s) {
        const int n = s.size();
        if (n == 1) {
            return s;
        }

        int maxCount = 0;
        char letter;
        unordered_map<char, int> freq;
        for (const char c : s) {
            freq[c] += 1;
            if (freq[c] > maxCount) {
                maxCount = freq[c];
                letter = c;
            }
        }

        if (maxCount > ((n + 1) / 2)) return "";

        string ans(n, 'a');
        int index = 0;

        // Place the most frequent letter
        while (freq[letter] != 0) {
            ans[index] = letter;
            index += 2;
            freq[letter]--;
        }

        // Place rest of the letters in any order
        for (auto [c, time] : freq) {
            while (time > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                ans[index] = c;
                index += 2;
                time--;
            }
        }

        return ans;
    }
};
int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}