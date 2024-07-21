#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 1) return n;
        
    //     unordered_set<int> record;
    //     for(int num : nums) {
    //         record.insert(num);
    //     }
        
    //     pair<int, int> result;
        
    //     for(int num : record) {
    //         if(num < result.first || num > result.first + result.second) { // if the current number is not in the longest Consecutive range, we try to update it
    //             int temp1 = num;
    //             while(record.count(temp1)) {
    //                 temp1--;
    //             }
                
    //             int temp2 = num;
    //             while(record.count(temp2)) {
    //                 temp2++;
    //             }
                
    //             if(temp2 - temp1 - 2 > result.second) {
    //                 result = {temp1 + 1, temp2 - temp1 - 2};
    //             }
    //         }else{
    //             continue;
    //         }
    //     }
        
    //     return result.second + 1;
    // }

    // The code can be simplified as following
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        unordered_set<int> record;
        for(int num : nums) {
            record.insert(num);
        }

        int max_len = 0;

        for(int num : record) {
            // we've met a number that does not have a left neighbor
            // which means it is the start point of a potential consecutive sequence
            if(!record.count(num - 1)) {
                int temp_ans = 1;

                while(record.count(++num)) {
                    temp_ans++;
                }

                max_len = max(temp_ans, max_len);
            }
        }

        return max_len;
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}