#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> ban_set(forbidden.begin(), forbidden.end());
        set<pair<int, bool>> isVisited;
        queue<pair<int, bool>> q;
        q.push({0, 0});
        isVisited.insert({0, 0});
        int result = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                
                if(cur.first == x) return result;
                
                pair<int, bool> forward = {cur.first + a, 0};
                if(forward.first <= 5000 + b && !isVisited.count(forward) && !ban_set.count(forward.first)) {
                    q.push(forward);
                    isVisited.insert(forward);
                }
                
                if(!cur.second) {
                    pair<int, bool> backward = {cur.first - b, 1};
                    if(backward.first > 0 && !isVisited.count(backward) && !ban_set.count(backward.first)) {
                        q.push(backward);
                        isVisited.insert(backward);
                    }   
                }
            }
            
            result++;
        }
    
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}