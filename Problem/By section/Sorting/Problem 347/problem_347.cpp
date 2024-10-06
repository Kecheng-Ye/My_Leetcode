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
        const int n = nums.size();
        if (n == 1) return {nums.front()};

        int maxFreq = 0;
        unordered_map<int, int> freq;
        for (const int& i : nums) {
            freq[i]++;
            maxFreq = max(maxFreq, freq[i]);
        }

        vector<vector<int>> buckets(maxFreq + 1);

        for (const auto& [num, frequency] : freq) {
            buckets[frequency].push_back(num);
        }

        vector<int> result(k);
        for (int i = maxFreq; (i >= 0) && (k > 0); i--) {
            if (buckets[i].empty()) continue;

            int bucketSize = buckets[i].size();
            while (bucketSize-- && k--) {
                result[k] = buckets[i][bucketSize];
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    return 0;
}