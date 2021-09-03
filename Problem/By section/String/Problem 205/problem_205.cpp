#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    bool isIsomorphic(string s, string t) {
        vector<int> record1(256, -1);
        vector<int> record2(256,  -1);
        
        
        int n1 = s.size();
        int n2 = t.size();
        
        for(int i = 0; i < n1; i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            if(record1[c1] == -1 && record2[c2] == -1) {
                record1[c1] = c2;
                record2[c2] = c1;
            }else{
                if(record1[c1] == c2 && record2[c2] == c1) {
                    continue;
                }
                
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}