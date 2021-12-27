#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    vector<int> in_degree;
    

    // Time: O(K*(E + V)), Space: O(V)
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        g = vector<vector<int>>(n);
        in_degree = vector<int>(n);
        
        for(const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            g[a].push_back(b);
            in_degree[b]++; // a go to b, so b's indegree should be incremented
        }
        
        int result = 1;
        
        unordered_set<char> record(colors.begin(), colors.end());
        
        for(auto c : record) {
            int cur = helper(colors, c);
            if(cur == -1) return -1;
            result = max(result, cur);
        }
        
        return result;
    }
    
    int helper(string& colors, int color) {
        int n = colors.size();
        vector<int> count(n);
        vector<int> temp_in(in_degree.begin(), in_degree.end());
        int visited = 0;
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(temp_in[i] == 0) {
                visited++;
                count[i] += (colors[i] == color);
                q.push(i);
            }
        }
        
        int result = 0;
        
        // Topological traverse
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(const int neighbour : g[cur]) {
                count[neighbour] = max(count[neighbour], count[cur] + (colors[neighbour] == color)); // update the count
                result = max(result, count[neighbour]);
                
                temp_in[neighbour]--;
                if(!temp_in[neighbour]) { // important here, all input of one node has been exhausted, then this node's indegree is 0,
                                          // we can put it into the queue
                    visited++;
                    q.push(neighbour);
                }
            }
        }
        
        return (visited == n) ? result : -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}