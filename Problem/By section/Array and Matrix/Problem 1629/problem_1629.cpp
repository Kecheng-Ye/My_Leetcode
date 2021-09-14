#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        int prev = 0, _max = 0;
        char result;
        
        for(int i = 0; i < n; i++) {
            int duration = releaseTimes[i] - prev;
            
            if(duration > _max) {
                result = keysPressed[i];
                _max = duration;
            }else if(duration == _max) {
                result = max(result, keysPressed[i]);
            }
            
            prev = releaseTimes[i];
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}