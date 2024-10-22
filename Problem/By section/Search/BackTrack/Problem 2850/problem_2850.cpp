#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // n = number of grid who has 0 stones
    // Time: O(n!) Space: O(n)
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> extra,less;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>1)extra.push_back({i,j});
                if(grid[i][j]==0)less.push_back({i,j});
            }
        }
        return helper(grid,extra,less,0);
    }
    int helper(vector<vector<int>> &grid,vector<pair<int,int>> &extra,vector<pair<int,int>> &less,int index){
        if(index>=less.size())return 0;
        int ans=1e9;
        pair<int,int> less_point=less[index];
        for(auto &extra_point:extra){
            int x=extra_point.first;
            int y=extra_point.second;
            if(grid[x][y]<=1)continue;
            grid[x][y]--;
            ans=min(ans,abs(less_point.first-x)+abs(less_point.second-y)+helper(grid,extra,less,index+1));
            grid[x][y]++;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}