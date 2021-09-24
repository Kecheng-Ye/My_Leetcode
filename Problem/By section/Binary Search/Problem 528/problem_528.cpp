#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) : pre_sum(w.size() + 1){
        nums = vector<int>(w);
        pre_sum[0] = nums[0];
        for(int i = 1; i < w.size(); i++) {
            pre_sum[i] += pre_sum[i - 1] + nums[i];
        }
        sum = pre_sum[w.size() - 1];
    }
    
    int pickIndex() {
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * sum;
        
        int low = 0, high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (target > pre_sum[mid])
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
private:
    vector<int> nums;
    vector<int> pre_sum;
    int sum;
};


int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}