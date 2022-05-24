#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        stack<int> min_s;
        stack<int> max_s;
        long long result = 0;
        
        for(int i = 0; i <= n; i++) {
            while(!min_s.empty() && (i == n || nums[i] < nums[min_s.top()])) {
                int idx = min_s.top();
                min_s.pop();
                int left = (min_s.empty()) ? idx + 1 : idx - min_s.top();
                int right = i - idx;
                result -= ((long long)left * right * nums[idx]);
            }
            
            min_s.push(i);
            
            while(!max_s.empty() && (i == n || nums[i] > nums[max_s.top()])) {
                int idx = max_s.top();
                max_s.pop();
                int left = (max_s.empty()) ? idx + 1 : idx - max_s.top();
                int right = i - idx;
                result += ((long long)left * right * nums[idx]);
            }
            
            max_s.push(i);
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}