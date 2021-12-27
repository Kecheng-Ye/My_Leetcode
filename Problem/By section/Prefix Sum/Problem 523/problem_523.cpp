#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> record;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % k;
            
            if(i > 0 && mod == 0) return true;
            
            if(record.count(mod)) {
                if(i - record[mod] > 1)
                return true;
            }else{
                record[mod] = i;
            }
            
        }
        
        return false;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}