#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(max(m, n)), Space: O(1)
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;

        while (i < word.size() && j < abbr.size()) {
            if (!isdigit(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                i++; j++;
            } else {
                if (abbr[j] == '0') return false;

                int count = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    count = count * 10 + (abbr[j++] - '0');
                }

                i += count;
            }
        }

        return (i == word.size()) && (j == abbr.size());
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}