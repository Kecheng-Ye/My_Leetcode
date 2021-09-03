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

                if((i > 1 && nums[i - 2] > nums[i]) && (i < size - 1 && nums[i - 1] > nums[i + 1])) {
                    return false;
                }
            }
        }

        return count < 2;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {5, 7, 1, 8};
    cout << s.checkPossibility(input) << endl;
    return 0;
}