#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        if(h == 1 && w == 1) return 1;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int prev = 0, start, _max_len = INT_MIN, _max_width = INT_MIN;
        
        for(auto& cut : verticalCuts) {
            start = cut;
            _max_len = max(start - prev, _max_len);
            prev = start;
        }
        
        _max_len = max(w - prev, _max_len);
        
        prev = 0, start;
        for(auto& cut : horizontalCuts) {
            start = cut;
            _max_width = max(start - prev, _max_width);
            prev = start;
        }
        
         _max_width = max(h - prev, _max_width);
        
        long long result = ((long long)_max_len * _max_width) % (1000000007);
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}