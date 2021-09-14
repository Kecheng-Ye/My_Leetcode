#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        
        unordered_set<int> record;
        
        for(int& num : nums) {
            if(record.count(num)) return true;
            record.insert(num);
        }
        
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}