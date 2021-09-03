#include <bits/stdc++.h>

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
        quickSort(nums, n, k, 0, n - 1);
        return nums[n - k];
    }

    void quickSort(vector<int>& nums, int n, int k, int start, int end) {
        if(start >= end) return;

        int piviot = rand() % (end - start) + start;
        int position = partition(nums, start, end, piviot);

        if(position == n - k) {
            return;
        }else if(position > n - k) {
            quickSort(nums, n, k, start, position - 1);
        }else{
            quickSort(nums, n, k, position + 1, end);
        }
    }

    int partition(vector<int>&nums, int start, int end, int piviot) {
        int target = nums[piviot];
        swap(nums, end, piviot);

        int i = start;
        int j = end - 1;

        while(true) {
            while(nums[i] <= target && i < end) {
                i++;
            }

            while(nums[j] > target && j > i) {
                j--;
            }

            if(i >= j) break;

            swap(nums, i, j);
        }

        if(i < end) swap(nums, i, end);

        return i;
    }

    void swap(vector<int>&nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
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