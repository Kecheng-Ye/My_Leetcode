#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), compare);
        int result = 0;
        
        int prev = -1;
        for(const auto& event : events) {
            int start = event[0];
            int end   = event[1];
            
            if(prev >= end) continue;
            
            prev = (start > prev + 1) ? start : prev + 1;
            result++;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}