#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // compare from first and last
    // need to count the number of digits for this number
    // Time: O(n), Space: O(1)
    // bool isPalindrome(int x) {
    //     if(x < 0) return false;
    //     if(x == 0) return true;
        
    //     int num_digits = log10(x) + 1;
        
    //     while(num_digits  > 1) {
    //         int leading = pow(10, num_digits - 1);
            
    //         if(x % 10 != x / (leading)) return false;
            
    //         x %= leading;
    //         x /= 10;
    //         num_digits -= 2;
    //     }
        
    //     return true;
    // }

    // directly spain the right half the number and compare with the left half    
    // Time: O(n), Space: O(1)
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int right = 0;
        while (x > right) {
            right = right * 10 + x % 10;
            x /= 10;
        }
        return x == right || x == right / 10; // the palindrom maybe odd or even number long
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}