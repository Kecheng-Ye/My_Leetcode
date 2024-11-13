#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(m * n) Space: O(m * n)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> graph = constructGraph(routes);
        
        queue<int> q;  // each node is a bus stop
        unordered_set<int> isVisited;  // how many buses have we wen to
        q.push(source);
        
        int step = 0;

        while (!q.empty()) {
            step++;
            int lvlSize = q.size();

            while (lvlSize--) {
                const int currStop = q.front(); q.pop();

                for (const auto& availableBus : graph[currStop]) {
                    if (isVisited.count(availableBus)) continue;

                    isVisited.insert(availableBus);

                    for (const auto& nextStop : routes[availableBus]) {
                        if (nextStop == target) return step;

                        q.push(nextStop);
                    }
                }
            }
        }

        return -1;

    }

private:
    // stop -> [avilable buses]
    unordered_map<int, vector<int>> constructGraph(const vector<vector<int>>& routes) {
        unordered_map<int, vector<int>> result;
        int count = 0;

        for (const auto& route : routes) {
            const int n = route.size();
            
            for (const auto& stop : route) {
                result[stop].push_back(count);
            }

            count++;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}