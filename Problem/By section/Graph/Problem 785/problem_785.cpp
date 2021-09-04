#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // BFS Approach
    // Categorize node into different part by their different level
    // then go through all of the edges to check if two ends exactly locate at different group
    // Time: O(E + V), Space: O(V)
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
        
    //     unordered_set<int> a;
    //     unordered_set<int> b;
    //     BFS(graph, a, b);
        
    //     for(int i = 0; i < n; i++) {
    //         for(int node : graph[i]) {
    //             if(a.count(node) && a.count(i) || b.count(node) && b.count(i)) return false;
    //         }
    //     }
        
        
    //     return true;
        
    // }
    
    // void BFS(vector<vector<int>>& graph, unordered_set<int>& a, unordered_set<int>& b) {
    //     queue<int> q;
    //     int round = 0;
    //     vector<bool> visited(graph.size(), false);
        
    //     for(int i = 0; i < graph.size(); i++) {
    //         if(visited[i]) continue;
            
    //         q.push(i);
            
    //         while(!q.empty()) {
    //             int size = q.size();
    //             round++;
                
    //             for(int j = 0; j < size; j++) {
    //                 int temp = q.front();
    //                 q.pop();
                    
    //                 if(round % 2 == 0) {
    //                     a.insert(temp);
    //                 }else{
    //                     b.insert(temp);
    //                 }
                    
    //                 visited[temp] = true;
                    
    //                 for(int node : graph[temp]) {
    //                     if(visited[node]) continue;
                        
    //                     q.push(node);
    //                 }
    //             }
    //         }
    //     }
    // }

    // DFS Approach
    // traverse each node and mark its neighbors as different color than itself's
    // check if all nodes being traversed or meet a conflicted edge
    // Time: O(E + V), Space: O(V)
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                stack<int> stk;
                stk.push(start);
                color[start] = 0;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();

                    for (int neigh : graph[node]) {
                        if (color[neigh] == -1) {
                            stk.push(neigh);
                            color[neigh] = color[node] ^ 1;
                        } else if (color[neigh] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}