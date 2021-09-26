#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> getFactors(int n) {
        if(n <= 3) return {};
        
        return backtrack(n, 2);
    }
    
    vector<vector<int>> backtrack(int n, int start) {
        if(n <= 3) return {};
        vector<vector<int>> result;
        while(start * start <= n) {
            if(n % start == 0) {
                int another = n / start;
                result.push_back({start, another});
                
                vector<vector<int>> decomposition = backtrack(another, start);
                for(const auto& lst : decomposition) {
                    vector<int> temp = lst;
                    temp.push_back(start);
                    result.push_back(temp);
                }
                
            }
            
            start += 1;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}