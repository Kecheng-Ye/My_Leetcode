#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        
        return a[0] < b[0];
    }
    
    static bool pq_compare(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    
    // choose the one end first
    // Time: O(nlogn), Space: O(n)
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        if(n == 1) return 1;
        
        sort(events.begin(), events.end(), compare);
        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> pq(pq_compare);
        
        int final_end = INT_MIN;

        int result = 0;
        int idx = 0;
        
        for(int i = 1; i <= 1e5; i++) {
            while(idx < n && events[idx][0] == i) {
                pq.push(events[idx]);
                idx++;
            }
            
            while(!pq.empty() && pq.top()[1] < i) {
                pq.pop();
            }
            
            if(!pq.empty()) {
                result += 1;
                pq.pop();
            }
        }
        
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}