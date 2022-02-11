#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node{
        int target;
        int distance;
        
        node(int v, int d): target(v), distance(d) {};
    };
    
    // Dijkstra Algo
    // Time: O(ElogV), Space: O(V)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<node>> graph = construct_graph(times, n);
        
        unordered_map<int, int> distance;
        priority_queue<node, vector<node>, function<bool(const node&, const node&)>> pq(compare);
        pq.push({k, 0});
        int count = 0;
        int result = INT_MIN;
        
        while(!pq.empty()) {
            const auto cur = pq.top();
            pq.pop();
            if(distance.count(cur.target)) continue;
            count++;
            distance[cur.target] = cur.distance;
            result = max(result, cur.distance);
            
            for(const auto& neighbour : graph[cur.target]) {
                int new_dis = neighbour.distance + cur.distance;
                if(!distance.count(neighbour.target) || new_dis < distance[neighbour.target]) {
                    pq.push({neighbour.target, new_dis});
                }
            }
        }
        
        
        return (count == n) ? result : -1;
    }
    
    vector<vector<node>> construct_graph(const vector<vector<int>>& times, int n) {
        vector<vector<node>> g(n + 1);
        
        for(const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
        }
        
        return g;
    }
    
    static bool compare(const node& a, const node& b) {
        return a.distance > b.distance;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}