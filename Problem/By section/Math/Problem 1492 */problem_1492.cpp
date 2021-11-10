#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // intuition: a number's divisor is [i_1, i_2, ..., i_n]
    //            where i_i * i_(n - i) = target number
    //            and the mid point of this divisor list is sqrt(target number)
    // we can first iterate over the first half of the list
    // and use the `i_i * i_(n - i)` mapping for another half
    // Time: O(sqrt(n)), Space: O(sqrt(n))
    int kthFactor(int n, int k) {
        vector<int> divisor;
        int limit = sqrt(n);
        
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                k--;
                
                if(k == 0) return i;
                
                divisor.push_back(i);
            }
        }
        
        
        
        if(limit * limit == n) k++;
        int length = divisor.size();
        
        return (k > length) ? -1 : n / (divisor[length - k]);
    }
    
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}