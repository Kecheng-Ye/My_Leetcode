#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<char> result;
    
    // Time: O(m^2), Space: O(m)
    string alienOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> graph(26, vector<int>(26, -1));
        
        // Trick when parsing precedence
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                int idx = 0;
                // skip same characters
                while(idx < words[i].size() && idx < words[j].size() && words[i][idx] == words[j][idx]) 
                    idx++;
                
                // meet contradictions
                if(idx < words[i].size() && idx == words[j].size()) return "";
                // meet end of the low precedence word
                if(idx == words[i].size()) continue;
                // remark there is a connection from words[i][idx](smaller) to words[j][idx](bigger)
                graph[words[i][idx] - 'a'][words[j][idx] - 'a'] = 1;
            }
        }
        
        
        vector<int> result;
        vector<bool> on_Path(26, false);
        vector<bool> isvisited(26, false);
        
        // Topological Sort
        for(const auto& str : words) {
            for(const auto& c : str) {
                if(!DFS(graph, result, on_Path, isvisited, (int)(c - 'a'))) return "";
            }
        }
        
        reverse(result.begin(), result.end());
        vector<char> final_result(result.size());
        for(int i = 0; i < result.size(); i++) {
            final_result[i] = (char)('a' + result[i]);
        }
        return string(final_result.begin(), final_result.end());
        
    }

    
    bool DFS(vector<vector<int>>& graph, vector<int>& result, vector<bool>& on_Path, vector<bool>& isvisited, int cur) {
        if(on_Path[cur]) return false;
        
        if(isvisited[cur]) return true;
        
        isvisited[cur] = true;
        on_Path[cur]   = true;
        
        for(int i = 0; i < 26; i++) {
            if(i != cur && graph[cur][i] == 1) {
                if(!DFS(graph, result, on_Path, isvisited, i)) 
                    return false;
            }
        }
        
        result.push_back(cur);
        on_Path[cur]   = false;
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}