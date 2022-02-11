#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        
        //            target number --- <start index, how many in the arr>
        unordered_map<int, pair<int, int>> record;
        int degree = 1;
        record[nums[0]] = pair<int, int>(0, 1);
        int result = 1;
        
        for(int i = 1; i < n; i++) {
            if(!record.count(nums[i])) {
                record[nums[i]] = make_pair(i, 1);
            }else{
                record[nums[i]].second++;
                if(record[nums[i]].second > degree) {
                    degree = record[nums[i]].second ;
                    result = i - record[nums[i]].first + 1;
                }else if(record[nums[i]].second == degree) {
                    result = min(result, i - record[nums[i]].first + 1);
                }
            }
        }
        
        return result;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}