#include <bits/stdc++.h>

using namespace std;

class Solution {
    using Encoding = pair<char, int>;
public:
    // Time: O(n + m), Space: O(n)
    int expressiveWords(string s, vector<string>& words) {
        const vector<Encoding> sEncoding = generateEncoding(s);

        int count = 0;
        for (const auto& word : words) {
            count += validateSingleWord(sEncoding, word);
        }
        return count;
    }

    bool validateSingleWord (const vector<Encoding>& sEncoding, const string& word) {
        const int m = sEncoding.size(), n = word.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            const auto& [currChar, freq] = sEncoding[i++];

            if (word[j] != currChar) return false;

            int k = j;
            while (k < n && word[j] == word[k]) k++;

            const int currLen = k - j;
            
            if (currLen > freq) return false;

            if (currLen < freq && freq < 3) return false;
            
            j = k;
        }

        return i == m && j == n;
    }

    vector<Encoding> generateEncoding(const string& s) {
        vector<Encoding> result;
        const int n = s.size();

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            result.emplace_back(s[i], j - i);
            i = j;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}