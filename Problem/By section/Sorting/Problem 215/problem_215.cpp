#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k ];
    // }

    // Time: O(nlogk), Space: O(k)
    // int findKthLargest(vector<int>& nums, int k) {
    //     // way to intialize a min heap
    //     auto compare = [](const int i, const int j) {return i > j;};
    //     priority_queue <int, vector<int>, decltype(compare)> pq(compare);

    //     for(int i = 0; i < nums.size(); i ++) {
    //         pq.push(nums[i]);

    //         if(pq.size() > k) pq.pop();
    //     }

    //     return pq.top();
    // }

    // Time: O(n), Space: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;

        const function<int(const int, const int)> quickSelect = [&](const int start, const int end) {
            if (start == end) return nums[start];

            int piviot = rand() % (end - start) + start;
            int position = partition(nums, start, end, piviot);

            if(position == k) {
                return nums[position];
            } else if (position > k) {
                return quickSelect(start, position - 1);
            } else {
                return quickSelect(position + 1, end);
            }
        };

        return quickSelect(0, n - 1);
    }


    int partition(vector<int>&nums, int start, int end, int piviot) {
        const int target = nums[piviot];
        swap(nums[end], nums[piviot]);

        int nextP = start;

        for (int i = start; i < end; i++) {
            if (nums[i] < target) {
                if (i != nextP) swap(nums[i], nums[nextP]);
                nextP++;
            }
        }

        swap(nums[end], nums[piviot]);

        return nextP;
    }
};

int main(int argc, char** argv) {
    vector<int> input{3,2,3,1,2,4,5,5,6};

    Solution solution;
    // std::cout << solution.findKthLargest(input, 4) << std::endl;
    // std::cout << ((false) << 1) << std::endl;

    int* a = NULL;
    int* b = a;
    cout << b << endl; 
    *b = 6;
    cout << b << endl; 

    return 0;
}