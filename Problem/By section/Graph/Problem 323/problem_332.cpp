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

// private:
//     class UnionFind {
//     public:
//         UnionFind(int n): ranks(n), parents(n), numOfGroups(n) {
//             for (int i = 0; i < n; i++) {
//                 parents[i] = i;
//             }
//         }

//         int find(int i) {
//             if (i != parents[i]) {
//                 parents[i] = find(parents[i]);
//             }
//             return parents[i];
//         }

//         void Union(int x, int y) {
//             int parentX = find(x);
//             int parentY = find(y);

//             if (parentX == parentY) {
//                 return;
//             } else {
//                 if (ranks[parentX] == ranks[parentY]) {
//                     parents[parentY] = parentX;
//                     ranks[parentX]++;
//                 } else if (ranks[parentX] > ranks[parentY]) {
//                     parents[parentY] = parentX;
//                 } else {
//                     parents[parentX] = parentY;
//                 }
//                 numOfGroups--;
//             }
//         }

//         const int getNumOfGroups() const {
//             return numOfGroups;
//         }        

//     private:
//         vector<int> ranks;
//         vector<int> parents;
//         int numOfGroups;
//     };    
// public:
//     // Time: O(E), Space: O(V)
//     int countComponents(int n, vector<vector<int>>& edges) {
//         UnionFind unionFind(n);

//         for (const auto& edge : edges) {
//             const int u = edge[0], v = edge[1];
//             unionFind.Union(u, v);
//         }

//         return unionFind.getNumOfGroups();
//     }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}