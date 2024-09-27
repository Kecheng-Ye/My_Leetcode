#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n1 + n2) Space: O(n1 + n2)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums2.size(), m = nums1.size();

        vector<int> nextBig(n);
        unordered_map<int, int> numToIdx;
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            const int currNum = nums2[i];
            // Everything that is smaller than currN will be excluded
            // as there can never be the next big number for nums2[0 : i -1]
            while (!s.empty() && s.top() <= currNum) {
                s.pop();
            }

            nextBig[i] = s.empty() ? -1 : s.top();
            s.push(currNum);
            numToIdx[currNum] = i;
        }

        vector<int> result(m);

        for (int i = 0; i < m; i++) {
            result[i] = nextBig[numToIdx[nums1[i]]];
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}