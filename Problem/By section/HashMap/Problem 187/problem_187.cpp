#include <bits/stdc++.h>

using namespace std;

#define MASK 0x3FFFFFFF  // only keep 3 * 10 = 30 bit
#define encodeOneDNA(curr) (curr & 7)  // 7 = 0b111
#define addOneDNA(prev, curr) ((prev << 3) & MASK | encodeOneDNA(curr))

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        vector<string> result;
        unordered_map<int, int> freqMap;

        int i = 0;
        int curr = 0;
        while (i < 10) {
            curr = addOneDNA(curr, s[i++]);
        }

        freqMap[curr] += 1;

        while (i < n) {
            curr = addOneDNA(curr, s[i++]);
            if (freqMap[curr]++ == 1) {
                result.push_back(s.substr(i - 10, 10));
            }
        }

        return result;

    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}