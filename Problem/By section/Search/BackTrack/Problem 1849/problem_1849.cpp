#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^2), Space: O(n)
    bool splitString(string s) {
        return backtrack(s, 0, -1, 0);
    }
    
    bool backtrack(string& s, int idx, long long target, int length) {
        if(idx == s.size() && length > 1) {
            return true;
        }else if(length > 0 && target < 0) {
            return false;
        }else{
            long long num = 0, n = s.size();
            for(int i = idx; i < n; i++) {
                num = num * 10 + (int)(s[i] - '0');
                if(length == 0) {
                    if(log10(num) > (n - i) + 1) break;
                    
                    if(backtrack(s, i + 1, num - 1, length + 1)) return true;
                }else{
                    if(num > target) break;
                
                    if(num == target) {
                        if(backtrack(s, i + 1, target - 1, length + 1)) return true;
                    }   
                }
            }
            
            return false;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}