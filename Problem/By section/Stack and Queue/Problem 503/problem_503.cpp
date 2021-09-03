#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return {-1};
        
        vector<int> result(size, -1);
        stack<int> s;

        for(int i = 0; i < size * 2; i++) {
            int cur = nums[i % size];
            
            while(!s.empty() && cur > nums[s.top()]) {
                result[s.top()] = cur;
                s.pop();
            }
            
            if(i < size) {
                s.push(i); // instead of pushing the actual num, we can push its index to the stack
            }
        }
        
        
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}