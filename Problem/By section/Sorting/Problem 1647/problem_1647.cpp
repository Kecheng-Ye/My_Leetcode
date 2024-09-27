#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int minDeletions(string s) {
        const int n = s.size();

        vector<int> freq(26);

        for (const char c : s) {
            freq[c - 'a'] += 1;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int step = 0;
        int last = freq[0];
        for (int i = 1; i < 26; i++) {
            if (freq[i] == 0) break;

            if (last == 0) {
                step += freq[i];
                continue;
            }


            if (freq[i] >= last) {
                step += (freq[i] - last + 1);
                freq[i] = last - 1;
            }
            last = freq[i];
        }

        return step;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}