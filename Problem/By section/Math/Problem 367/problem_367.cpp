#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
//     bool isPerfectSquare(int num) {
//         if(num <= 1) return true;
        
//         int i = 2, j = (int)(num / 2);
        
//         while(i <= j) {
//             int mid = i + (j - i) / 2;
//             double result = (num / (double)mid) - (double)(mid);
//             if(result == 0.0) {
//                 return true;
//             }else if(result > 0){
//                 i = mid + 1;
//             }else{
//                 j = mid - 1;
//             }
//         }
        
//         return false;
//     }
    
    // Time: O(sqrt(n)), Space: O(1)
    bool isPerfectSquare(int num) {
        int diff = 1;
        
        while(num > 0) {
            num -= diff;
            diff += 2;
        }
        
        return (num == 0);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}