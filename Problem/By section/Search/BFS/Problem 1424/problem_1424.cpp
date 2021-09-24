#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(mn), Space: O(mn)
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        queue<pair<int, int>> q;
        vector<int> result;
        q.push({0, 0});
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto coord = q.front();
                int j = coord.first, k = coord.second;
                q.pop();
                result.push_back(nums[j][k]);
                
                if(j + 1 < n && k == 0) {
                    q.push({j + 1, k});
                }
                
                if(nums[j].size() > k + 1) {
                    q.push({j, k + 1});
                }
            }
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}