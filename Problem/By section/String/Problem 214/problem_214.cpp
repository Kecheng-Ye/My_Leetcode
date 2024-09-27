#include <bits/stdc++.h>

using namespace std;

// Brute Force
// class Solution {
// public:
//     // Time: O(n^2) Space: O(n)
//     string shortestPalindrome(string s) {
//         const string t = {s.rbegin(), s.rend()};
//         const string_view sv_s(s);
//         const string_view sv_t(t);

//         for (int i = 0; i < s.length(); ++i)
//             if (sv_s.substr(0, s.length() - i) == sv_t.substr(i))
//             return t.substr(0, i) + s;

//         return t + s;
//     }
// };

#define HASH_LIMIT 29
#define mod ((long)1e9 + 7)

// Rolling Hash
class Solution {
public:
    // Time: O(n) Space O(1)
    string shortestPalindrome(string s) {
        const int n = s.size();
        int biggestPaliIdx = -1;
        long long prefixHash = 0;
        long long suffixHash = 0;
        long long power = 1; 

        for (int i = 0; i < n; i++) {
            const long long curr = s[i] - 'a' + 1;
            prefixHash = (prefixHash * HASH_LIMIT + curr) % mod;
            suffixHash = (curr * power + suffixHash) % mod;
            power = (power * HASH_LIMIT) % mod;

            if (prefixHash == suffixHash) {
                biggestPaliIdx = i;
            }
        }

        string targetSuffix = s.substr(biggestPaliIdx + 1);
        reverse(targetSuffix.begin(), targetSuffix.end());
        return targetSuffix + s;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}