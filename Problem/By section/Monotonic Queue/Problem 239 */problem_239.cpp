#include <bits/stdc++.h>

using namespace std;

// This is a implementation of a max monotonicQueue
class MonotonicQueue {
public:
    // once we push a val into the queue, we will pop everything that is less than the queue
    void push(int val) { 
        while(!data.empty() && data.back() < val) { 
            data.pop_back();
        }

        data.push_back(val);
    }

    // pop the front one, which is the biggest one
    void pop() {
        data.pop_front();
    }

    int max() const { 
        return data.front();
    }

private:
    deque<int> data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return vector<int>(1, *max_element(nums.begin(), nums.end()));

        vector<int> result(n - k + 1, 0);
        MonotonicQueue mq;
        
        for(int i = 0; i < n; i++) {
            mq.push(nums[i]);

            if(i >= k - 1) { // if we are out of the sliding window, we will try to delete the element
                result[i - k + 1] = mq.max(); // first update the previous sliding window's max

                // then check if the previous max is exactly the element which pop from the previous sliding window
                if(nums[i - k + 1] == mq.max()) mq.pop();
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}