#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> record(n, false);
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if(record[i]) continue;
            int cnt = 0;
            
            while(!record[i]) {
                record[i] = true;
                cnt++;
                i = nums[i];
            }
            
            result = max(result, cnt);
        }
        
        return result;
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}