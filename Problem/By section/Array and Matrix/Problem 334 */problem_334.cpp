#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for (const int num : nums) {
            if (num <= smallest) {
                smallest = num;
            } else if (num <= secondSmallest) {
                secondSmallest = num;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}