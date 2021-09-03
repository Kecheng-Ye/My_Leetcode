#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        for(auto i : s) {
            frequency[i]++;
        }

        int max = 0;
        vector<vector<char>> buckets(s.length() + 1);
        for(auto pair : frequency) {
            max = (max > pair.second) ? max : pair.second;
            buckets[pair.second].push_back(pair.first);
        }

        string result;

        for(int i = max; i >=0; i--) {
            if(buckets[i].size() == 0) continue;

            for(int j = 0; j < buckets[i].size(); j++) {
                for(int k = 0; k < i; k++) {
                    result += buckets[i][j];
                }
            }
        }

        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.frequencySort("aabbc");

    return 0;
}