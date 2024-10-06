#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        int result = 0;
        int temp = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            temp += nums[i];

            if (temp == k) result++;
            result += record[temp - k];

            record[temp] += 1;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}