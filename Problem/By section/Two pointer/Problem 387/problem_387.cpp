#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int firstUniqChar(string s) {
        int n = s.size();
        if(n == 1) return 0;
        
        int result = 0;
        vector<int> record(26, 0);
        
        for(int i = 0; i < n; i++) {
            if(!record[s[i] - 'a']) {
                record[s[i] - 'a']++;
            }else{
                record[s[i] - 'a']++;
                if(s[result] == s[i]) {
                    while(result < n && record[s[result] - 'a'] > 1) {
                        result++;
                    }
                }
            }
        }
        
        return result >= n ? -1 : result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}