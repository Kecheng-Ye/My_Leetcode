#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(isBadVersion(mid)) {
                right = mid - 1;
            }else if(!isBadVersion(mid)) {
                left = mid + 1;
            }
        }

        if(left > n) return -1;

        return left;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}
