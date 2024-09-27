#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n ^ 2), Space: O(1)
    vector<int> pancakeSort(vector<int>& arr) {
        const int n = arr.size();
        if (n == 1) return {};
        
        vector<int> result;
        const function<void(vector<int>&, const int)> helper = [&](vector<int>& arr, const int limit) {
            if (limit == 1) {
                return;
            }

            const auto currMax = max_element(arr.begin(), arr.begin() + limit);
            // reverse the cur max to the top
            reverse(arr.begin(), currMax + 1);
            result.push_back((currMax + 1) - arr.begin());
            // then reverse the top max to the bottom
            reverse(arr.begin(), arr.begin() + limit);
            result.push_back(limit);

            helper(arr, limit - 1);
        };

        helper(arr, n);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}