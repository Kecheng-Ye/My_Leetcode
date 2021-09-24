#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cur_best;
    
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        if(n == 1) return words[0];
        
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int m = words[i].size();
                int n = words[j].size();
                cost[i][j] = words[j].size();
                for(int k = 1; k < min(m, n); k++) {
                    if(words[i].substr(m - k) == words[j].substr(0, k))
                        cost[i][j] = n - k;
                }
            }
        }
        
        cur_best = INT_MAX;
        vector<int> path(n, -1);
        vector<int> candidate(n, -1);
        vector<bool> isVisited(n, false);
        backtrack(path, candidate, words, cost, 0, isVisited, 0);
        
        string result = "";
        for(int i = 0; i < n; i++) {
            if(i - 1 < 0) {
                result += words[path[i]];
            }else{
                int m = path[i - 1];
                int n = path[i];
                result += words[n].substr(words[n].length() - cost[m][n]);
            }
        }
        
        return result;
    }
    
    void backtrack(vector<int>& result, vector<int>& candidate, vector<string>& words, vector<vector<int>>& cost, int idx, vector<bool>& isVisited, int cur_len) {
        if(cur_len >= cur_best) {
            return;
        }else if(idx == words.size()) {
            cur_best = cur_len;
            result = vector<int>(candidate); 
            return;
        }else{
            for(int i = 0; i < words.size(); i++) {
                if(isVisited[i]) continue;
                
                isVisited[i] = true;
                candidate[idx] = i;
                
                backtrack(result, candidate, words, cost, idx + 1, isVisited, 
                          (idx == 0) ? words[i].size() : cur_len + cost[candidate[idx - 1]][i]);
                
                candidate[idx] = -1;
                isVisited[i] = false;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}