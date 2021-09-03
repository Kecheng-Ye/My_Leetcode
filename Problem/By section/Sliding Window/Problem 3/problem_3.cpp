#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;
        
        int left = 0, right = 0, result = 0;
        vector<int> record(256, -1);
        
        while(right < n) {
            if(record[s[right]] == -1) {
                record[s[right]] = right;
                right++;
                result = max(result, right - left);
            }else{
                record[s[left++]] = -1;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}