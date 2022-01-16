#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
//     string customSortString(string order, string s) {
//         unordered_map<char, int> record;
        
//         for(int i = 0; i < order.size(); i++) {
//             record[order[i] - 'a'] = i;
//         }
        
//         auto compare = [&](const char a, const char b) {
//             return record[a - 'a'] < record[b - 'a'];
//         };
        
//         sort(s.begin(), s.end(), compare);
//         return s;
//     }
    
    // Time: O(n), Space: O(n)
    string customSortString(string order, string s) {
        vector<int> counts(26);
        
        for(int i = 0; i < s.size(); i++) {
            counts[s[i] - 'a']++;
        }
        
        vector<char> result(s.size());
        int idx = 0;
        
        for(int i = 0; i < order.size(); i++) {
            if(counts[order[i] - 'a']) {
                int& cnt = counts[order[i] - 'a'];
                
                while(cnt) {
                    result[idx++] = order[i];
                    cnt--;
                }
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(counts[i]) {
                while(counts[i]) {
                    result[idx++] = (char)(i + 'a');
                    counts[i]--;
                }
            }
        }
   
        return string(result.begin(), result.end());
    }
};