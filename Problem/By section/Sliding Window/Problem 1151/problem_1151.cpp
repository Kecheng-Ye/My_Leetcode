#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // sliding window, always keep a window with size `ones`
    // and check how many zeros in this window
    // Time: O(n), Space: O(1)
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(const int i : data)
            ones += 1;

        int cnt_one = 0, max_one = 0;
        int left = 0, right = 0;

        while (right < data.size()) {
            // updating the number of 1's by adding the new element
            cnt_one += data[right++];
            // maintain the length of the window to ones
            if (right - left > ones) {
                // updating the number of 1's by removing the oldest element
                cnt_one -= data[left++];
            }
            // record the maximum number of 1's in the window
            max_one = max(max_one, cnt_one);
        }
        return ones - max_one;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}