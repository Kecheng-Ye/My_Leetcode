#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // DFS Approach
    // Time: O(n + qn), Space: O(n)
    // vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    //     unordered_map<string, vector<pair<string, double>>> graph = construct_graph(equations, values);
    //     int n = queries.size();
    //     vector<double> result(n);
        
        
    //     for(int i = 0; i < n; i++) {
    //         string a = queries[i][0];
    //         string b = queries[i][1];
            
    //         unordered_set<string> record;
    //         result[i] = DFS(graph, a, b, record);
    //     }
        
    //     return result;
        
    // }
    
    // unordered_map<string, vector<pair<string, double>>> construct_graph(vector<vector<string>>& equations, vector<double>& values) {
    //     int n = equations.size();
    //     unordered_map<string, vector<pair<string, double>>> graph;
        
        
    //     for(int i = 0; i < n; i++) {
    //         string a = equations[i][0];
    //         string b = equations[i][1];
    //         graph[a].push_back({b, values[i]});
    //         graph[b].push_back({a, 1 / values[i]});
    //     }
        
    //     return graph;
    // }
    
    // double DFS(unordered_map<string, vector<pair<string, double>>>& graph, string a, string b, unordered_set<string>& visited) {
    //     if(!graph.count(a) || !graph.count(b)) {
    //         return -1;
    //     }
        
    //     if(a == b) return 1;
        
    //     visited.insert(a);
        
    //     for(const auto& neighbour : graph[a]) {
    //         string node = neighbour.first;
    //         if(visited.count(node)) continue;
            
    //         double result = DFS(graph, node, b, visited);
            
    //         if(result > 0) return neighbour.second * result; 
    //     }
        
    //     return -1;
    // }
    
    // Disjoint set approach
    // Time: O(n + q), Space: O(n)
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Union_set s(equations);
        
        int n = equations.size();
        
        for(int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            s.Union(a, b, val);
        }
        
        int m = queries.size();
        vector<double> result(m);
        
        for(int i = 0; i < m; i++) {
            result[i] = s.query(queries[i][0], queries[i][1]);
        }
        
        
        return result;
    }
    
    class Union_set{
    public:
        Union_set(vector<vector<string>>& equations) {
            int n = equations.size();

            for(int i = 0; i < n; i++) {
                string a = equations[i][0];
                string b = equations[i][1];

                if(!parent.count(a)) {
                    parent[a] = {a, 1.0};
                    rank[a]   = 1;
                }

                if(!parent.count(b)) {
                    parent[b] = {b, 1.0};
                    rank[b]   = 1;
                }
            }
        }

        void Union(string a, string b, double val) {
            if(!parent.count(a) || !parent.count(b)) return;

            auto pa = Find(a);
            auto pb = Find(b);

            if(pa.first == pb.first) {
                return;
            }else if(rank[pa.first] == rank[pb.first]){
                parent[pb.first] = {pa.first, (val * pa.second / pb.second)};
                rank[pa.first]++;
            }else if(rank[pa.first] > rank[pb.first]) {
                parent[pb.first] = {pa.first, (val * pa.second / pb.second)};
            }else {
                parent[pa.first] = {pb.first, 1 / (val * pa.second / pb.second)};
            }
        }

        pair<string, double> Find(string a) {
            if(a != parent[a].first) {
                auto result = Find(parent[a].first);
                parent[a].first = result.first;
                parent[a].second = result.second * parent[a].second;
            }

            return parent[a];
        }

        double query(string a, string b) {
            if(!parent.count(a) || !parent.count(b)) return -1;

            auto pa = Find(a);
            auto pb = Find(b);

            if(pa.first != pb.first) {
                return -1;
            }else{
                return pb.second / pa.second;
            }
        }

    private:
        unordered_map<string, int> rank;
        unordered_map<string, pair<string, double>> parent;
                              //   parent name, value that times node itself equals parent
                              //   e.g node = a, parent = x,  value = x/a                 
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}