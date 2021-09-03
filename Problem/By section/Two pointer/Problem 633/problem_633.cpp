#include <bits/stdc++.h>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while(left <= right) {
            long long result = pow(left, 2) + pow(right, 2);
            if(result == c) {
                return true;
            }else if(result < c){
                left++;
            }else{
                right--;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    return 0;
}