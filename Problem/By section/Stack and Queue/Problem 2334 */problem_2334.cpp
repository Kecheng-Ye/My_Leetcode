#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int n = nums.size();
        if (n == 1 && nums[0] < threshold) return -1;

        vector<int> left(n, - 1), right(n, n);

        // two pass
        // stack<pair<int, int>> monotonicSt;
        // for (int i = 0; i < n; i++) {
        //     while (!monotonicSt.empty() && monotonicSt.top().first >= nums[i]) {
        //         monotonicSt.pop();
        //     }

        //     if (monotonicSt.empty()) {
        //         left[i] = -1;
        //     } else {
        //         left[i] = monotonicSt.top().second;
        //     }
        //     monotonicSt.push({nums[i], i});
        // }

        // monotonicSt = stack<pair<int, int>>();

        // for (int i = n - 1; i >= 0; i--) {
        //     while (!monotonicSt.empty() && monotonicSt.top().first >= nums[i]) {
        //         monotonicSt.pop();
        //     }

        //     if (monotonicSt.empty()) {
        //         right[i] = n;
        //     } else {
        //         right[i] = monotonicSt.top().second;
        //     }
        //     monotonicSt.push({nums[i], i});
        // }

        // one pass
        stack<int> stk;
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && nums[i] < nums[stk.top()]){
                // if skt.top get evicted
                // then we pretty issue nums[i] is the right closest number that is greater than nums[skt.top()]
                int idx = stk.top();
                stk.pop();
                right[idx] = i;
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            stk.push(i);
        }

        for (int i = 0; i < n; i++) {
            int leftPos = left[i];
            int rightPos = right[i];

            if (nums[i] > (threshold)/ (rightPos - leftPos - 1)) {
                return (rightPos - leftPos - 1);
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}