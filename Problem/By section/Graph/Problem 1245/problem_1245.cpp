#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(V + E), Space: O(V)
    int treeDiameter(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<vector<int>> graph(n + 1);

        for (const auto& edge : edges) {
            const int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int maxPath = 0;
        vector<bool> isVisited(n + 1);
        const function<int(const int, const int)> dfs = [&](const int currNode, const int parentNode) {
            isVisited[currNode] = true;

            int topDistance1 = 0, topDistance2 = 0;
            
            for (const int neighbor : graph[currNode]) {
                if (neighbor == parentNode) continue;
                if (isVisited[neighbor]) continue;
                const int tempDepth = 1 + dfs(neighbor, currNode);
                if (tempDepth > topDistance1) {
                    topDistance2 = topDistance1;
                    topDistance1 = tempDepth;
                } else if (tempDepth > topDistance2) {
                    topDistance2 = tempDepth;
                }
            }

            maxPath = max(maxPath, topDistance1 + topDistance2);

            return max(topDistance1, topDistance2);
        };

        dfs(0, -1);
        return maxPath;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}