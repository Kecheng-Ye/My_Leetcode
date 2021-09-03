#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Time: O(n), Space: O(n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if(!m) return vector<vector<int>>{};

        int n = heights[0].size();

        unordered_set<int> Pacific;
        unordered_set<int> Atlantic;

        for(int i = 0; i < m; i++) {
            dfs(heights, Pacific, i, 0, m, n);
            dfs(heights, Atlantic, i, n - 1, m, n);
        }

        for(int i = 0; i < n; i++) {
            dfs(heights, Pacific, 0, i, m, n);
            dfs(heights, Atlantic, m - 1, i, m, n);
        }

        vector<vector<int>> result;
        for(auto& i : Pacific) {
            if(Atlantic.count(i)) {
                int y = i % n;
                int x = (int)((i - y) / n);
                result.push_back({x, y});
            }
        }

        return result;
    }

    bool check_valid(unordered_set<int>& record, int x, int y, int m, int n) {
        int idx = x * n + y;
        return (x < 0 || y < 0 || x >= m || y >= n || record.count(idx));
    }

    void dfs(vector<vector<int>>& heights, unordered_set<int>& record, int x, int y, int m, int n){
        int idx = x * n + y;

        record.insert(idx);

        for(auto& direction : directions) {
            int new_x = x + direction[0];
            int new_y = y + direction[1];

            if(check_valid(record, new_x, new_y, m, n) || heights[x][y] > heights[new_x][new_y]) continue;

            dfs(heights, record, new_x, new_y, m, n);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}