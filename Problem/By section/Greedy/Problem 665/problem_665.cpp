#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return true;

        int count = 0;
        for(int i = 1; i < size && count < 2; i++) {
            if(nums[i] < nums[i - 1]) {
                count++;

                // for a sub sequence [a1, a2, a3, a4]
                // we have a2 > a3
                // 1. if a1 < a3, then we can change a2 to a3, result array [a1, a3, a3, a4] will be valid
                // 2. if a2 < a4, then we can change a3 to a2, result array [a1, a2, a2, a4] will be valid
                // 3. Otherwise, we can not resolve the conflict
                if(count > 1 ||
                    (
                        (i > 1 && nums[i - 2] > nums[i]) &&
                        (i < size - 1 && nums[i - 1] > nums[i + 1])
                    )
                ) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {5, 7, 1, 8};
    cout << s.checkPossibility(input) << endl;
    return 0;
}
