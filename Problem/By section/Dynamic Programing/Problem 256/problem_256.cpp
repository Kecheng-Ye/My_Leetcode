#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Red[i]:      minimum cost when painting ith house in red
    // Blue[i]:     minimum cost when painting ith house in blue
    // Green[i]:    minimum cost when painting ith house in green
    // Red[i] = min(Blue[i - 1], Green[i - 1]) + costs[i][red]
    // Time: O(n), Space: O(1)
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        int red = costs[0][0];
        int blue = costs[0][1];
        int green = costs[0][2];
        
        for(int i = 1; i < n; i++) {
            int new_red, new_blue, new_green;
            
            new_red = min(blue, green) + costs[i][0]; 
            new_blue = min(red, green) + costs[i][1]; 
            new_green = min(blue, red) + costs[i][2]; 
            
            red = new_red;
            blue = new_blue;
            green = new_green;
        }
        
        return min(min(red, blue), green);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}