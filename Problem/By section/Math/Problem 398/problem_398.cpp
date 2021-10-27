#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        inputs = vector<int>(nums.begin(), nums.end());
        n = nums.size();
    }
    
    // Reservoir Sampling
    // Time: O(n), Space: O(1)
    int pick(int target) {
        int count = 0;
        int result;
        
        for(int i = 0; i < n; i++) {
            if(inputs[i] == target) {
                result = ((rand() % (++count)) == 0) ? i : result;
            }
        }
        
        return result;
    }
    
private:
    vector<int> inputs;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}