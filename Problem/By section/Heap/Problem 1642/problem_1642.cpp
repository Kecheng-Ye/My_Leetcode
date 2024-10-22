#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn) Space: O(n)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
                
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n - 1; i++) {
            int gap = heights[i + 1] - heights[i];
            if(gap <= 0) continue;
            
            pq.push(gap);
            if(pq.size() > ladders) {
                auto smallest = pq.top();
                if(smallest > bricks) {
                    return i;
                }
                
                bricks -= smallest;
                pq.pop();
            }
        }
        
        return n - 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}