#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        long long diff = 0;
        
        for(int num : nums) {
            diff ^= num;
        }
        
        diff &= -diff; // get the right most different one bit 
        
        for(int num : nums) {
            // & opeartion is lower than == !!!!!!
            if((num & diff) == 0) { 
                result[0] ^= num;
            }else{
                result[1] ^= num;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}