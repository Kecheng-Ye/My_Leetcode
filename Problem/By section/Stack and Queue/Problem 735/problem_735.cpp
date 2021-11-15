#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        if(n == 1) return asteroids;
        
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            if(dq.empty()) {
                dq.push_back(asteroids[i]);
            }else{
                if(asteroids[i] > 0) {
                    dq.push_back(asteroids[i]);
                }else{
                    while(!dq.empty()) {
                        auto prev = dq.back();
                        if(prev < 0) {
                            dq.push_back(asteroids[i]);
                            break;
                        }else{
                            if(prev == abs(asteroids[i])) {
                                dq.pop_back();
                                break;
                            }else if(prev > abs(asteroids[i])) {
                                break;
                            }else{
                                dq.pop_back();
                                
                                if(dq.empty()) { 
                                    dq.push_back(asteroids[i]);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        vector<int> result(begin(dq), end(dq));
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}