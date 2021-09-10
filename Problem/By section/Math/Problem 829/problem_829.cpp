#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    Insight:
    1 | x 
    2 | x + (x+1) = 2x + 1 <==> n-1 = 2x
    3 | x + (x+1) + (x+2) = 3x + 3 <==> n-3 = 3x
    4 | 4x + 6 <==> n-6 = 4x

    the offset is the sum of the previous integers
    */

    // Time: O(sqrt(n)), Space: O(1)
    int consecutiveNumbersSum(int n) {
        int count = 0;
        int i = 1;
        while(n > 0){
            n = n-i;
            if(n % i == 0) count++;
            i++;
        }
        return count;
    }


    // Time: O(n), Space: O(1)
    // int consecutiveNumbersSum(int n) {
    //     if(n <= 2) return 1;
        
    //     int limit = n / 2 + 1;
        
    //     int left = 1; int right = 1;
    //     int count = 1;
    //     int cur_sum = 0; 
        
    //     while(right <= limit) {
    //         cur_sum += right;
    //         right++;
            
    //         if(cur_sum == n) {
    //             count++;
    //         }
            
    //         while(cur_sum >= n) {
    //             cur_sum -= left;
    //             left++;
                
    //             if(cur_sum == n) {
    //             count++;
    //             }
    //         }
    //     }
        
    //     return count;
    // }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}