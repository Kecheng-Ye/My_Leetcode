#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Kruskal's algorithm
    // Time: O(ElogE) Space: O(V)
    int minimumCost(int n, vector<vector<int>>& connections) {
        if(n == 1) return 0;
        
        auto compare = [&](const vector<int>& edge_a, const vector<int>& edge_b){
            return edge_a[2] < edge_b[2];
        };
        
        int result = 0;
        Disjoint_set ds(n);
        sort(connections.begin(), connections.end(), compare);
        
        
        for(int i = 0; i < connections.size(); i++) {
            auto& least = connections[i];
            
            if(ds.Find_parents(least[0]) == ds.Find_parents(least[1])) continue;
            result += least[2];
            ds.Union(least[0], least[1]);
            
            if(ds.is_all_connected()) return result;
        
        }
        
        return -1;
    }

private:
    class Disjoint_set {
    public:
        Disjoint_set(int n) {
            parents = vector<int>(n + 1);
            ranks = vector<int>(n + 1, 1);
            group = n;
            
            
            for(int i = 1; i <= n; i++) {
                parents[i] = i;
            }
        }
        
        void Union(int i, int j) {
            int pi = Find_parents(i);
            int pj = Find_parents(j);
            
            if(pi == pj) {
                return;
            }else if(ranks[pi] == ranks[pj]) {
                parents[pj] = pi;
                ranks[pi]++;
            }else if(ranks[pi] > ranks[pj]) {
                parents[pj] = pi;
            }else{
                parents[pi] = pj;
            }
            
            group--;
        }
        
        int Find_parents(int i) {
            if(i != parents[i]) {
                parents[i] = Find_parents(parents[i]);
            }
            
            return parents[i];
        }
        
        int is_all_connected() {
            return group == 1;
        }
        
    private:
        vector<int> parents;
        vector<int> ranks;
        int group;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}