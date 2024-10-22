#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        //     currNum -> PrevMinBeforCurrNum
        stack<pair<int, int>> st;
        int prevMin = INT_MAX;

        for (int i = 0; i < n; i++) {
            const int currNum = nums[i];
            prevMin = min(prevMin, currNum);
            
            while (!st.empty() && currNum >= st.top().first) {
                st.pop();
            }

            if (!st.empty()) {
                const auto& [potentialJ, potentialI] = st.top();
                if (potentialI != potentialJ && currNum > potentialI) return true;
            }

            st.push({currNum, prevMin});
        }

        return false; 
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}