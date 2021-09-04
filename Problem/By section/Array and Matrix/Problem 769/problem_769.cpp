#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 1;
        
        int _min = 0, _max = 0; // mantain the range of current sort arr
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            _min = i;
            int j;
            for(j = i; j < n; j++) {
                _max = max(arr[j], _max);
                
                if(j - i == _max - _min) break;
            }
            
            i = j;
            result++;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}