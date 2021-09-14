#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(t.size), Space: O(t.size)
    // Note: only we construct the letterIndicesTable for once, then for all the following query, we only need Time: O(s.size)
    bool isSubsequence(string s, string t) {
        // precomputation, build the hashmap out of the target string
        unordered_map<char, vector<int>> letterIndicesTable;
        for (int i = 0; i < t.length(); ++i) {
            letterIndicesTable[t[i]].push_back(i);
        }

        int currMatchIndex = -1;
        for (char letter : s) {
            if (!letterIndicesTable.count(letter))
                return false; // no match, early exist

            bool isMatched = false;
            // greedy match with linear search
            for (int matchIndex : letterIndicesTable[letter]) {
                if (currMatchIndex < matchIndex) { // if you meet an 'a' at index 1, you cannot match the 'a' at index 0 in t, because the 0 index is for other char
                    currMatchIndex = matchIndex;
                    isMatched = true;
                    break;
                }
            }

            if (!isMatched)
                return false;
        }

        // consume all characters in the source string
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}