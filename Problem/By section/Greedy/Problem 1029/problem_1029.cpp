#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    
    // Time: O(nlogn), Space: O(n)
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        sort(costs.begin(), costs.end(), compare);
        
        int result = 0;
        for(int i = 0; i < n; i++) {
            result += (i < n / 2) ? costs[i][0] : costs[i][1];
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}