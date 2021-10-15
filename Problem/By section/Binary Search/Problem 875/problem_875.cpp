#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int _max    = *max_element(piles.begin(), piles.end());
        int left    = 1;
        int right   = _max;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            int finish_time = eat(piles, mid);
            
            if(finish_time == h) {
                right = mid;
            }else if(finish_time < h) {
                right = mid;
            }else if(finish_time > h) {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    int eat(vector<int>& piles, int k) {
        int result = 0;
        for(const auto& pile : piles) {
           result += (pile % k == 0) ? pile / k :  pile / k + 1;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}