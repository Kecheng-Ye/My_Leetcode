#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        if(n == 1) return 0;
        
        vector<int> record(60, 0);
        int result = 0;
        
        for(const auto& num : time) {
            result += record[(60 - num % 60) % 60];
            record[num % 60]++;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}