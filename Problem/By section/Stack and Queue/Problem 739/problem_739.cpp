#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if(size == 1) return {0};
        
        vector<int> result(size, 0);
        stack<pair<int, int>> s;
        s.push({temperatures[size - 1], size - 1});
        
        for(int i = size - 2; i >= 0; i--) {
            int today = temperatures[i];
            
            while(!s.empty() && today >= s.top().first) {
                s.pop();
            }
            
            if(s.empty()) {
                result[i] = 0;
            }else{
                result[i] = s.top().second - i;
            }
            
            s.push({temperatures[i], i});
        }
        
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}