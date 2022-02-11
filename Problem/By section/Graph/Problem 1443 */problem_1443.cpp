#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int result;
    // Time: O(n), Space: O(n)
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        result = 0;
        vector<vector<int>> graph = construct_graph(n, edges);
        unordered_map<int, int> visited;
        unordered_set<int> apple_trace;
        
        BFS(graph, hasApple);
        
        return result;
    }
    
    vector<vector<int>> construct_graph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return graph;
    }
    
    int traverse_back(int i, unordered_map<int, int>& visited, unordered_set<int>& apple_trace) {
        int cur = i;
        int result = 0;
        
        while(!apple_trace.count(cur)) {
            if(cur == 0) break;
            
            ++result;
            apple_trace.insert(cur);
            cur = visited[cur];
        }
        
        return 2 * result;
    }
    
    void BFS(vector<vector<int>>& graph, vector<bool>& hasApple) {
        unordered_map<int, int> visited;
        unordered_set<int> apple_trace;
        queue<int> q;
        q.push(0);
        visited[0] = -1;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                const auto node = q.front();
                q.pop();
                
                if(hasApple[node]) {
                    result += traverse_back(node, visited, apple_trace);
                }
                
                for(const auto& neighbour : graph[node]) {
                    if(!visited.count(neighbour)) {
                        visited[neighbour] = node;
                        q.push(neighbour);
                    }
                }
            }
        }
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}