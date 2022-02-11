#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(!n) return 0;
        
        int cur_profit = 0;
        int total_profit = 0;
        int cur_start = 0;
        
        for(int i = 0; i < n; i++) {
            cur_profit += (gas[i] - cost[i]);
            total_profit += (gas[i] - cost[i]);
            
            if(cur_profit < 0) {
                cur_start = i + 1;
                cur_profit = 0;
            }
        }
        
        return (total_profit < 0) ? -1 : cur_start;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}