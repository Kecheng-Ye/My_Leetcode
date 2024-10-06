#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int n = s.size();

        if (n <= 2) return n;

        unordered_map<char, int> freq;
        int left = 0, right = 0;

        int result = 0;
        while (right < n) {
            const char curr = s[right++];
            freq[curr] += 1;

            while (!checkIfValid(freq)) {
                const char charToEvict = s[left++];
                freq[charToEvict] -= 1;
            }

            result = max(result, right - left);
        }
        return result;
    }

private:
    bool checkIfValid(unordered_map<char, int>& freq) {
        int result = 0;

        for (const auto& [_char, frequency] : freq) {
            result += (frequency > 0);
        }

        return result <= 2;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}