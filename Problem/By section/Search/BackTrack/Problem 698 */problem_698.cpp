#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int n = nums.size();
        const int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k) {
            return false;
        }

        vector<int> buckets(k, 0);
        const int targetSum = totalSum / k;
        
        //Optimize :Reverse sort so that bigger numbers get rejected early on in the expansion tree
        sort(nums.begin(),nums.end(), greater<int>());

        //Optimize: If any match is bigger than the expected side
        for(auto a : nums)
            if (a > targetSum) return false;

        const auto isGoodPartition = [&]() {
            for (const auto& bucket : buckets) {
                if (bucket != targetSum) return false;
            }
            return true;
        };

        //Optimize 2:
        // lets say sides are currently : [5,7,5,9] , the next element is 3.
        // Therefore we will be applying dfs on the following:
        // [5+3,7,5,9]
        // [5,7+3,5,9]
        // [5,7,5+3,9]
        // [5,7,5,9+3]
        // First and third are basically the same, only in a different order. 
        // If in the first case, dfs returned false, the third case will return false too.
        // So we don't run dfs in third case.
        const auto seenBefore = [&](const int i){
            for (int k = 0; k < i; k++) {
                if (buckets[i] == buckets[k]) {
                    return true;
                }
            }
            return false;
        };

        const function<bool(const int)> backtrack = [&](const int idx) {
            if (idx == n && isGoodPartition()) {
                return true;
            }
            
            const int currNum = nums[idx];

            for (int i = 0; i < k; i++) {
                if (buckets[i] + currNum > targetSum) {
                    continue;
                }
                
                if (seenBefore(i)) continue;

                buckets[i] += currNum;

                if (backtrack(idx + 1)) {
                    return true;
                }

                buckets[i] -= currNum;
            }

            return false;
        };
        
        return backtrack(0);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}