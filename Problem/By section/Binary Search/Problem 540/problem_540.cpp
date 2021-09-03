#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        int mid;

        while(left < right) {
            mid = left + (right - left) / 2;
            // if we reach left or right bound
            if(mid == 0 || mid == size - 1) {
                break;
            }else if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            }else if(nums[mid - 1] != nums[mid]) { // if the mid is not equal to the left
                // and the num of number left in the left part is not even 
                if((mid - left) % 2 != 0) {
                    // the answer must be in the left part
                    right = mid - 1;
                }else {
                    left = mid;
                }
            }else if(nums[mid + 1] != nums[mid]) { // same for rights
                if((right - mid) % 2 != 0) {
                    left = mid + 1;
                }else {
                    right = mid;
                }
            }
        }

        return nums[left];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {1,1,2,2,3,3,4,8,8};
    cout << s.singleNonDuplicate(input) << endl;
    return 0;
}