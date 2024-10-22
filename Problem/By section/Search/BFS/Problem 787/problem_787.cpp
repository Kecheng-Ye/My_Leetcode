#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(V + E), Space: O(V + E)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const vector<vector<pair<int, int>>> graph = constructGraph(n, flights);

        unordered_map<int, int> distance;
        for (int i = 0; i < n; i++) {
            distance[i] = INT_MAX;
        }
        
        queue<pair<int, int>> q;

        q.push({src, 0});
        distance[src] = 0;

        k += 1;

        while (!q.empty() && k--) {
            int currLvl = q.size();
            
            while (currLvl--) {
                const auto curr = q.front(); q.pop();

                distance[curr.first] = min(distance[curr.first], curr.second);

                for (const auto& [neighborNode, dist] : graph[curr.first]) {
                    const int newDist = curr.second + dist;

                    if (distance[neighborNode] > newDist) {
                        distance[neighborNode] = newDist;
                        q.push(
                            {neighborNode, newDist}
                        );
                    }
                }
            }
        }

        return (distance[dst] == INT_MAX) ? -1 : distance[dst];
    }

    vector<vector<pair<int, int>>> constructGraph(const int n, const vector<vector<int>>& flights) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& edge : flights) {
            const int from = edge[0], to = edge[1], price = edge[2];
            graph[from].push_back({to, price});
        }

        return graph;
    } 
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}