#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int answer = 0;

//         vector<int> visited(isConnected.size(), 0);
        
//         for(int i = 0; i < isConnected.size(); i++) {
//             if(visited[i] == 1) continue;
            
//             for(int j = i; j < isConnected[0].size(); j ++) {
//                 if(isConnected[i][j] == 1) {
                    
//                     if(visited[i] == 0) answer ++;
                    
//                     explore(isConnected, i, j, visited);
//                 }
//             }
//         }
        
//         return answer;
//     }
    
//     void explore(vector<vector<int>>& isConnected, int i, int j, vector<int>& visited) {
//         if(visited[j] != 0 || isConnected[i][j] != 1) return;
    
//         visited[i] = 1;
        
//         for(int k = 0; k < isConnected[0].size(); k++) {
//             explore(isConnected, j, k, visited);
//         }
//     }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if(size <= 1) return size;
        
        vector<bool> is_visited(size, false);
        int result = 0;
        
        for(int i = 0; i < size; i++) {
            if(!is_visited[i]) {
                result++;
                dfs(isConnected, i, is_visited);
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& isConnected, int city, vector<bool>& is_visited) {
        if(is_visited[city]) return;
        
        is_visited[city] = true;
        
        for(int i = 0; i < isConnected[city].size(); i++) {
            if(isConnected[city][i]) {
                dfs(isConnected, i, is_visited);
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}