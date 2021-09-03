#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> freq_table;

    //     for(int i = 0; i < nums.size(); i++) {
    //         int num = nums[i];

    //         if(freq_table.count(num)) {
    //             freq_table[num]++;
    //         }else {
    //             freq_table[num] = 1;
    //         }
    //     }

    //     vector<vector<int>> buckets(freq_table.size());

    //     for(auto pair : freq_table) {
    //         buckets.push_back(vector<int>{pair.first, pair.second});
    //     }

    //     sort(buckets.begin(), buckets.end(), [](const vector<int>& a, const vector<int>& b){
    //         return a[1] > b[1];
    //     });

    //     vector<int> result(k);

    //     for(int i = 0; i < k; i++) {
    //         result[i] = buckets[i][0];
    //     }

    //     return result;
    // }

    // Time: O(n), Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result{};
        unordered_map<int, int> freq_table;

        for(int i : nums) {
            freq_table[i]++;    
        }

        
        vector<vector<int>> buckets(nums.size() + 1);
        
        int max = 0;
        for(auto& pair : freq_table) {
            max = (pair.second > max) ? pair.second : max;
            buckets[pair.second].push_back(pair.first);
        }
    

        for(int i = max; i > 0 && k > 0; i--) {
            if(buckets[i].size() == 0) continue;

            for(auto ele : buckets[i]) {
                if(k <= 0) break;
                result.push_back(ele);
                k--;
            }
        }

        return result;
        
    }
};

int main(int argc, char** argv) {
    return 0;
}