#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        
        if(size <= 1) return 0;

        int result = 0;
        int prev = prices[0];
        for(int i = 1; i < size; i++) {
            if(prices[i] > prev) {
                result += prices[i] - prev;
            }

            prev = prices[i];
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {1, 2, 3, 4, 5};
    cout << s.maxProfit(input) << endl;
    return 0;
}