#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(mn), Space: O(mn)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(!n) return {};
        
        unordered_map<string, vector<string>> record;
        for(const auto& str : strs) {
            record[hash(str)].push_back(str);
        }
        
        
        vector<vector<string>> result;
        for(const auto& [key, lst] : record) {
            result.push_back(lst);
        }
        
        return result;
    }
    
    string hash(const string& str) {
        vector<int> rec(26);
        
        for(const char c : str) {
            rec[(c - 'a')]++;
        }
        
        string result;
        
        for(int i = 0; i < 26; i++) {
            result += (to_string(rec[i]) + '#');
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}