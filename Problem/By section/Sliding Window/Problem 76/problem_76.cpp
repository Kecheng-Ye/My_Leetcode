#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, int> constructFreMap(const string& t) {
        unordered_map<char, int> result;

        for (const char c : t) {
            result[c]++;
        }

        return result;
    }

    bool isTargetCovered(
        const unordered_map<char, int>& target, const unordered_map<char, int>& curr
    ) {
        for (const auto& [c, targetFreq] : target) {
            if (!curr.count(c) || (*curr.find(c)).second < targetFreq) return false;
        }

        return true;
    }

    // Time: O(54 * n), Space: O(1)
    // string minWindow(string s, string t) {
    //     const unordered_map<char, int> targetFreqMap = constructFreMap(t);

    //     unordered_map<char, int> windowFreqMap;
    //     int left = 0, right = 0;
    //     const int n = s.size();
    //     int currLen = INT_MAX;
    //     pair<int, int> index;

    //     while (right < n) {
    //         windowFreqMap[s[right++]]++;

    //         while (isTargetCovered(targetFreqMap, windowFreqMap)) {
    //             if (right - left < currLen) {
    //                 currLen = right - left;
    //                 index.first = left;
    //                 index.second = right;
    //             }
    //             windowFreqMap[s[left++]]--;
    //         }
    //     }

    //     if (currLen == INT_MAX) return "";
    //     return s.substr(index.first, currLen);
    // }

    // Time: O(n), Space: O(1)
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreqMap = constructFreMap(t);

        unordered_map<char, int> windowFreqMap;
        int left = 0, right = 0;
        const int n = s.size();
        int valid = 0;
        int currLen = INT_MAX;
        pair<int, int> index;

        while (right < n) {
            windowFreqMap[s[right]]++;
            if (
                targetFreqMap.count(s[right]) && 
                // devil here, cannot use '>=' because once we passed the required for one char
                // should not increment valid anymore for following same character
                targetFreqMap[s[right]] == windowFreqMap[s[right]]
            ) {
                valid++;
            }
            right++;
            
            while (valid == targetFreqMap.size()) {
                if (right - left < currLen) {
                    currLen = right - left;
                    index.first = left;
                    index.second = right;
                }

                windowFreqMap[s[left]]--;

                if (
                    targetFreqMap.count(s[left]) && 
                    targetFreqMap[s[left]] > windowFreqMap[s[left]]
                ) {
                    valid--;
                }

                left++;
            }
        }

        if (currLen == INT_MAX) return "";
        return s.substr(index.first, currLen);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}