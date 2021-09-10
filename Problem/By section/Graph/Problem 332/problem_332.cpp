#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(E + V), Space: O(E + V)
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n == 1) return 1;
        
        vector<bool> visited(n, false); 
        vector<vector<int>> graph = construct_graph(n, edges);
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            
            DFS(graph, visited, i);
            result++;
        }
        
        return result;
    }
    
    vector<vector<int>> construct_graph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        
        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        return g;
    }
    
    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int current) {
        if(visited[current]) return;
        
        visited[current] = true;
        
        for(int neighbour : graph[current]) {
            DFS(graph, visited, neighbour);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}