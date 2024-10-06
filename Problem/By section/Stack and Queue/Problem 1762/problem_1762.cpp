#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n) Space: O(n)
    vector<int> findBuildings(vector<int>& heights) {
        const int n = heights.size();
        if (n == 1) return {0};

        stack<int> st;
        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
            }

            if (st.empty()) result.push_back(i);
            st.push(heights[i]); 
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}