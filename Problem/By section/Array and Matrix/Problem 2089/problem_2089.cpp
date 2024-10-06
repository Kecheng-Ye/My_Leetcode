#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThan = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < target) lessThan++;
            if(nums[i] == target) count++;
        }

        vector<int> answer;

        for(int i = 0, j = 0; i < count; i++, j++) {
            answer.push_back(lessThan + j);
        }

        return answer;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}