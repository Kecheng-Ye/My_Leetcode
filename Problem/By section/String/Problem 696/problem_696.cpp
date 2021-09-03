#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int countBinarySubstrings(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        
        int first = 0, second = 0;
        int result = 0;
        
        while(first <= n - 1) {
            int cnt = first;
            char temp = s[first];
            
            while(s[cnt] == temp){
                cnt++;
            }
            
            second = cnt;
            temp = s[second];
            
            while(cnt < n && s[cnt] == temp) {
                cnt++;
            }
            
            result += min(second - first, cnt - second);
            first = second;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}