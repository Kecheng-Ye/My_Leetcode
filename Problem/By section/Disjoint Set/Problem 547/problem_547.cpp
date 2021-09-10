#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint_Set ds(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) ds.Union(i, j);
            }
        }
        
        return ds.group;
    }
    
private: 
    class Disjoint_Set{
    public:
        int group;
        
        Disjoint_Set(int size) {
            parent = vector<int>(size);
            rank = vector<int>(size, 0);
            
            group = size;
            
            for(int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }
        
        void Union(int i, int j) {
            int par_i = find_parents(i);
            int par_j = find_parents(j);
            
            if(par_i == par_j) return;
            
            if(rank[par_i] == rank[par_j]) {
                rank[par_i]++;
                parent[par_j] = par_i;
            }else if(rank[par_i] > rank[par_j]) {
                parent[par_j] = par_i;
            }else{
                parent[par_i] = par_j;
            }
            
            group--;
        }
        
        int find_parents(int i) {
            if(i != parent[i]) {
                parent[i] = find_parents(parent[i]);
            }
            
            return parent[i];
        }
        
    private:
        vector<int> parent;
        vector<int> rank;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}