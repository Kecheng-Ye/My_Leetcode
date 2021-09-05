#include <bits/stdc++.h>

using namespace std;

class Union_set{
public:
    Union_set(int size) {
        parents = vector<int>(size, 0);
        rank = vector<int>(size, 0);
        
        for(int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }
    
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) return false;
        
        if(rank[pu] == rank[pv]) {
            rank[pu]++;
            parents[pv] = pu;
        }else if(rank[pu] > rank[pv]) {
            parents[pv] = pu;
        }else {
            parents[pu] = pv;
        }
        
        return true;
    }
    
    int Find(int u) {
        if(u != parents[u]) {
            parents[u] = Find(parents[u]);
        }
        
        return parents[u];
    }
    
private:
    vector<int> parents;
    vector<int> rank;
};

class Solution {
public:
    // Time: O(E), Space: O(V)
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Union_set s(n + 1);
        
        for(const auto& edge : edges) {
            if(!s.Union(edge[0], edge[1])) return edge;
        }
        
        return {};
    }
    

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}