#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node {
        int num;
        int pos;
    };
    
    // Time: O(n), Space: O(n)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<node> s;
        vector<int> range(n, 0);
        
        // from left to right
        for(int i = 0; i < n; i++) {
            while(!(s.empty() || s.top().num <= heights[i])) {
                const auto prev = s.top();
                s.pop();
                
                range[prev.pos] += (i - prev.pos - 1);
            }
            
            s.push({heights[i], i});
        }
        
        if(!s.empty()) {
            const auto last = s.top();
            s.pop();
            
            while(!s.empty()) {
                const auto prev = s.top();
                s.pop();
                
                range[prev.pos] += (last.pos - prev.pos);
            }
        }
        
        // from right to left
        for(int i = n - 1; i >= 0; i--) {
            while(!(s.empty() || s.top().num <= heights[i])) {
                const auto prev = s.top();
                s.pop();
                
                range[prev.pos] += (prev.pos - i - 1);
            }
            
            s.push({heights[i], i});
        }
        
        if(!s.empty()) {
            const auto last = s.top();
            s.pop();
            
            while(!s.empty()) {
                const auto prev = s.top();
                s.pop();
                
                range[prev.pos] += (prev.pos - last.pos);
            }
        }
        
        
        int result = INT_MIN;
        for(int i = 0; i < n; i++) {
            result = max(result, heights[i] * (range[i] + 1));
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}