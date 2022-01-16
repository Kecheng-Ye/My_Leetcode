#include <bits/stdc++.h>

using namespace std;

#define encode(x, y) ((long long)x << 32) | ((long long)y)

class Solution {
public:
    // Time: O(3^n), Space: O(n)
    bool canCross(vector<int>& stones) {
        unordered_set<long long> is_seen;
        unordered_set<int> record(stones.begin(), stones.end());
        is_seen.insert(0);
        return DFS(0, 0, is_seen, record, stones.back());
    }
    
    // Basically a traverse for a tree with 3 children for each node + memo
    bool DFS(int loc, int step, unordered_set<long long>& is_seen, unordered_set<int>& stones, int target) {
        if(loc == target) return true;
        
        for(int i = -1; i <= 1; i++) {
            int new_step = step + i;
            int new_loc = loc + new_step;
            
            if(new_step <= 0 || is_seen.count(encode(new_step, new_loc)) || !stones.count(new_loc)) continue;
            
            is_seen.insert(encode(new_step, new_loc));
            
            if(DFS(new_loc, new_step, is_seen, stones, target)) return true;
        }
        
        return false;
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}