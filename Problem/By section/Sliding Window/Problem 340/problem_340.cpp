#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if(k == 0) return 0;
        unordered_map<char, int> record;
        
        
        int left = 0, right = 0;
        int result = 0;
        while(right < n) {
            if(!record[s[right]]) k--;
            
            while(k < 0) {
                record[s[left]]--;
                if(record[s[left]] == 0) k++;
                left++;
            }
            
            // printf("%d %d %d\n", right, left, k);
            
            result = max(result, right - left + 1);
            record[s[right++]]++;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}