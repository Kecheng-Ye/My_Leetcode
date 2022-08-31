#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(t.size), Space: O(t.size)
    // Note: only we construct the letterIndicesTable for once, then for all the following query, we only need Time: O(s.size + log(t.size))
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
            int greedy_result = binary_search(letterIndicesTable[letter], currMatchIndex);

            if (greedy_result == -1)
                return false;

            currMatchIndex = greedy_result;
        }

        // consume all characters in the source string
        return true;
    }

    int binary_search(vector<int>& letterIndices, int target) {
        int i = 0, j = letterIndices.size();

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (letterIndices[mid] <= target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }

        if (i >= letterIndices.size()) return -1;
        return letterIndices[i];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
