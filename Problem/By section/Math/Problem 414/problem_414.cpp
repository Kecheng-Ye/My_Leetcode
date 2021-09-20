#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int thirdMax(vector<int>& nums) {
        unordered_set<int> record;
        // max3 > max2 > max1
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; 
        for(const int& num : nums) {
            if(record.count(num)) continue;
            
            if(num > max3) {
                max1 = max2;
                max2 = max3;
                max3 = num;
            }else if(num > max2) {
                max1 = max2;
                max2 = num;
            }else if(num > max1) {
                max1 = num;
            }
            
            record.insert(num);
        }
        
        if(record.size() < 3) return max3;
        
        return max1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}