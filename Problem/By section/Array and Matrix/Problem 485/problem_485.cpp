#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, cur = 0;
        for(int i : nums) {
            cur = (i == 0) ? 0 : cur + 1;
            result = max(cur, result);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}