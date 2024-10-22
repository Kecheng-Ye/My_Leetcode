#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int visitedNodeNum;
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = constructGraph(n, edges);
        vector<bool> isVisited(n);
        visitedNodeNum = 0;
        if (!traverse(0, -1, graph, isVisited)) return false;
        if (visitedNodeNum < n) return false;
        return true;
    }

    vector<vector<int>> constructGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);

        for (const auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            result[u].push_back(v);
            result[v].push_back(u);
        }

        return result;
    }

    bool traverse(const int i, const int parent, vector<vector<int>>& graph, vector<bool> isVisited) {
        if (isVisited[i]) return false;

        isVisited[i] = true;
        visitedNodeNum++;
        for (const auto& neigbor : graph[i]) {
            if (neigbor == parent) continue;
            if (!traverse(
                neigbor,
                i,
                graph,
                isVisited
            )) return false;
        }

        return true; 
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}