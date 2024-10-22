#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    bool isIsomorphic(string s, string t) {
        vector<int>sMap(256 , -1);
        vector<int>tMap(256 , -1);

        for(int i = 0; i < s.length(); i++) {
            if(sMap[s[i]] != tMap[t[i]]) return false;

            sMap[s[i]] = i;
            tMap[t[i]] = i;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}