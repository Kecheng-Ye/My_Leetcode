#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums, i, left);
                left++;
            }
        }
        //upper for loop will put all zeroes at the start
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums, i, left);
                left++;
            }
        }
        //this for loop will put all ones after all zeroes and hence array is sorted now
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

};


int main() {
    Solution s;
    vector<int> input{2,1,0};
    s.sortColors(input);
    for(auto i : input) {
        cout << i << " ";
    }
}