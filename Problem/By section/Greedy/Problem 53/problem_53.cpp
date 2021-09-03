#include <bits/stdc++.h>

using namespace std;

// {-2, 1, -3, 4, -1, 2, 1, -5, 4}
// {1, -3}

class Solution {
public:
    // Time: O(n), Space: O(1)
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int temp = INT_MIN;

        for(auto& i : nums) {
            if(temp < 0) {
                temp = i;
            }else{
                temp += i;
            }

            if(max_sum < temp) {
                max_sum = temp;
            }
        }

        return max_sum;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {5, 4, -1, 7, 8};
    cout << s.maxSubArray(input) << endl;
    return 0;
}