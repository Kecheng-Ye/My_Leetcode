#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int day = try_ship(weights, mid);
            
            if(day > days) {
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return l;
    }
    
    int try_ship(vector<int>& weights, int limit) {
        int result = 1;
        int cur_weight = 0;
        for(const auto& weight : weights) {
            if(cur_weight > limit - weight) {
                result++;
                cur_weight = weight;
            }else{
                cur_weight += weight; 
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}