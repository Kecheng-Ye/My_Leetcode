#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000") || dead.count(target)) return -1;
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                string cur = q.front();
                q.pop();
                
                if(cur == target) return step;
                
                for(int j = 0; j < 4; j++) {
                    string new_node(cur);
                    char ori = new_node[j];
                    for(int k = -1; k <= 1; k += 2) {
                        char change = (ori - '0' + k + 10) % 10 + '0';
                        
                        new_node[j] = change;
                        if(dead.count(new_node) || visited.count(new_node)) continue;

                        visited.insert(new_node);
                        q.push(new_node);   
                    }
                    new_node[j] = ori;
                }
            }
            
            step++;
        }
        
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}