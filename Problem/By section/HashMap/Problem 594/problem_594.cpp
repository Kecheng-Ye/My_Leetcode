#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(N), Space: O(n)
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> record;
        int result = 0;
        
        for(int num : nums) {
            record[num]++;
        }
        
        for(auto& ele : record) {
            int cur = (record.count(ele.first - 1)) ? record[ele.first - 1] + ele.second : 0;
            result = max(cur, result);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}