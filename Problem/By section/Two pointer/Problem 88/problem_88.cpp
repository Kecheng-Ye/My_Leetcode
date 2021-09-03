#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_1 = m - 1;
        int ptr_2 = n - 1;
        int result_ptr = m + n - 1;

        while(result_ptr >= 0) {
            if(ptr_1 < 0) {
                nums1[result_ptr--] = nums2[ptr_2--];
            }else if(ptr_2 < 0) {
                nums1[result_ptr--] = nums1[ptr_1--];
            }else{
                if(nums1[ptr_1] >= nums2[ptr_2]) {
                    nums1[result_ptr--] = nums1[ptr_1--];
                }else{
                    nums1[result_ptr--] = nums2[ptr_2--];
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> input_1{1,2,3,0,0,0};
    vector<int> input_2{2,5,6};
    solution.merge(input_1, 3, input_2, 3);
    for(int i : input_1) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    return 0;
}