#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // n = len(arr), k = maxNum(arr1, arr2)
    // Time: O(nlog(k)), Space: O(nlog(k))
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix1 = generatePrefixSet(arr1);
        unordered_set<int> prefix2 = generatePrefixSet(arr2);

        int longestPrefix = 0;
        for (const int currPrefix : prefix1) {
            if (prefix2.count(currPrefix)) {
                longestPrefix = max(longestPrefix, currPrefix);
            }
        }

        if (longestPrefix == 0) return 0;

        int len = 0;
        while (longestPrefix) {
            len++;
            longestPrefix /= 10;
        }

        return len;
    }

    unordered_set<int> generatePrefixSet(const vector<int>& arr) {
        unordered_set<int> prefix;

        for (int num : arr) {
            while (num) {
                prefix.insert(num);
                num /= 10;
            }
        }

        return prefix;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}