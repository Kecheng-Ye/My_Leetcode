#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        int mid;

        while(left < right) {
            mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }else if(nums[mid] < nums[right]) {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {3, 1, 2};
    cout << s.findMin(input) << endl;
    return 0;
}