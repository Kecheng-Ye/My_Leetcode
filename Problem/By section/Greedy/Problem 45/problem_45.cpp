#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Greedy logic
    // Always jump to the furthest point we can reach in each step
    // Time: O(n), Space: O(1)
    int jump(vector<int>& nums) {
        int jump = 0, current = 0, n = nums.size();
        int farthest = -1;

        for(int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == current) {
                jump++;
                current = farthest;
                if (current >= n - 1) return jump;
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
