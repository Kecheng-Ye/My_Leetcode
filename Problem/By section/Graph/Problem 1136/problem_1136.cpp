#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> in_degree(n + 1);
        
        auto graph = construct_graph(n, relations, in_degree);
        
        queue<int> q;
        
        for(int i = 1; i <= n; i++) {
            if(in_degree[i] == 0) q.push(i);
        }
        
        int count = 0;
        int result = 0;
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                
                for(const auto neighbour : graph[cur]) {
                    in_degree[neighbour]--;
                    
                    if(in_degree[neighbour] == 0) q.push(neighbour);
                }
            }
            
            result++;
            count += size;
        }
        
        return (count == n) ? result : -1;
    }
    
    vector<vector<int>> construct_graph(int n, vector<vector<int>>& relations, vector<int>& in_degree) {
        vector<vector<int>> g(n + 1);
        
        for(const auto& relation : relations) {
            int prev = relation[0];
            int after = relation[1];
            in_degree[after]++;
            
            g[prev].push_back(after);
        }
        
        return g;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}