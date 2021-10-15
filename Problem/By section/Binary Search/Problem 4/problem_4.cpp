#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        
        int k = (m + n + 1) / 2;
        int l = 0, r = m;
        int m1, m2;
        
        while(l < r) {
            m1 = l + (r - l) / 2;
            m2 = k - m1;
            if(nums1[m1] < nums2[m2 - 1]) { // won't need to check m2 > 0 or not, because m2 == 0 will only happen if m == n and l == r, which will terminate the loop first
                l = m1 + 1;
            }else{
                r = m1;
            }
        }
        
        m1 = l;
        m2 = k - m1;
        
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                     m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
        
        if((m + n) % 2 != 0) return c1;
        
        int c2 = min(m1 >= m ? INT_MAX : nums1[m1],
                     m2 >= n ? INT_MAX : nums2[m2]);
        
        return (c1 + c2) * 0.5;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}