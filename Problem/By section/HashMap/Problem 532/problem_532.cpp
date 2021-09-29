#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int result = 0;
        unordered_map<int, int> freqs;
        
        for(const auto& num : nums) {
            freqs[num]++;
        }
        
        for(const auto& ele : freqs) {
            int num = ele.first;
            int freq = ele.second;
            
            if(k > 0 && freqs.count(k + num)) {
                result++;
            }else if(k == 0 && freq > 1) {
                result++;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}