#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    int mySqrt(int x) {
        if(x <= 0) return 0;

        int left = 0, right = x;
        long long int mid, square;

        // we only have one solution for this question
        while(left <= right) {
            // avoid overflow
            mid = left + (right - left)/2;
            square = pow(mid, 2);

            if(square > x) {
                right = mid - 1;
            }else if(square < x) {
                left = mid + 1;
            }else if(square == x) {
                return mid;
            }
        }

        // if get out the loop then left > right
        // we will use right as the answer
        return right;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}