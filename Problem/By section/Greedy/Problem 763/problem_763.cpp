#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Jump game approach
    // Time: O(n), Space: O(1)
    vector<int> partitionLabels(string s) {
       vector<int> last_pos(26, -1);
        int n = s.size();

        if (n <= 1) return {n};

        for (int i = 0; i < n; i++) {
            last_pos[s[i] - 'a'] = i;
        }

        vector<int> result;
        int cur_boundary = 0;
        int prev_point = 0;

        for (int i = 0; i < n; i++) {
            if (cur_boundary < i) {
                int length = cur_boundary + 1 - prev_point;
                result.push_back(length);
                prev_point = i;
            }
            cur_boundary = max(cur_boundary, last_pos[s[i] - 'a']);
        }

        result.push_back(n - prev_point);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    string input = "ababcbacadefegdehijhklij";
    auto result = s.partitionLabels(input);
    for(auto s : result) {
        cout << s << " ";
    }

    cout << endl;
    return 0;
}
