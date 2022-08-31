#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> higher;
        unordered_map<int, int> exitList;   // a hashmap that keeps all the number that supposed to be delete
        vector<double> result(n - k + 1);

        for (int i = 0; i < k; i++) {
            lower.push(nums[i]);
        }

        // k / 2 means that lower can at most have 1 more value that is in the sliding window than higher
        for (int i = 0; i < k / 2; i++) {
            higher.push(lower.top());
            lower.pop();
        }

        for (int i = 0; i <= n - k; i++) {
            // calculate current median
            double cur_median = (k & 1) ? lower.top() : ((double)lower.top() + higher.top()) / 2;
            result[i] = cur_median;

            if (i == n - k) break;

            int outNumber = nums[i];
            int inNumber = nums[i + k];
            exitList[outNumber]++;

            int balance = 0;

            // if out number is in the higher half
            // if we want to kick it out
            // there will be more number in the lower half
            if (outNumber > lower.top()) {
                --balance;
            } else {
                ++balance;
            }

            // if in number is in the higher half
            // there will be more number in the higher half
            if (inNumber > lower.top()) {
                ++balance;
                higher.push(inNumber);
            } else {
                --balance;
                lower.push(inNumber);
            }

            // balance can either be -2, 0, 2
            // if 0, no action need be performed
            // if 2, pop one from higher and push it to lower
            // if -2, pop one from lower and push it to higher
            if (balance > 0) {
                lower.push(higher.top());
                higher.pop();
            } else if (balance < 0) {
                higher.push(lower.top());
                lower.pop();
            }

            // after above operation
            // high.top() and lower.top() may not be the number in the sliding window
            // need to delete those value untill top value is inside sliding window
            while (exitList[lower.top()]) {
                exitList[lower.top()]--;
                lower.pop();
            }

            while (!higher.empty() && exitList[higher.top()]) {
                exitList[higher.top()]--;
                higher.pop();
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
