#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n + k), Space: O(1)
    vector<int> findAnagrams(string s, string p) {
        vector<int> record(26, 0);

        for(const auto& c : p) {
            record[c - 'a']++;
        }

        int left = 0, right = 0;
        int n = s.size();
        int k = p.size();
        vector<int> result;
        unordered_set<char> unique_char(p.begin(), p.end());

        while(right < n) {
            record[s[right++] - 'a']--;

            if(right - left == k) {
                bool valid = true;

                for(const auto& c : unique_char) {
                    if(record[c - 'a']) {
                        valid = false;
                        break;
                    }
                }

                if(valid) result.push_back(left);
                record[s[left++] - 'a']++;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
