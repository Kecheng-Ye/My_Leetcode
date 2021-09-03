#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        vector<int> result;

        for(int i = 0; i < s.length(); i++) {
            char character = s[i];
            if(map.count(character)) continue;

            map[character] = find_last_appear(s, character, i);
        }

        int prev = -1;
        for(int i = 0; i < s.length(); i++) {
            int start = i;
            int partition_end = map[s[start]];

            while(start < partition_end) {
                partition_end = max(partition_end, map[s[++start]]);
            }

            result.push_back(partition_end - prev);
            
            prev = partition_end;
            i = partition_end;
        }

        return result;

    }

    int find_last_appear(string& s, char target, int idx) {
        int i = s.length() - 1;
        while(i > idx) {
            if(s[i] == target) break;
            i --;
        }
        return i;
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