#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        int i = 0, j = n - 1;
        int currMax = INT_MIN;

        while (i < j) {
            currMax = max(
                currMax, 
                min(height[i], height[j]) * (j - i)
            );

            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return currMax;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}