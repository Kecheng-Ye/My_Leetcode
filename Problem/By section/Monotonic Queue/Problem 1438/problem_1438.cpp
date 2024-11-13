#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class MonotonicQueue {
    public:
        MonotonicQueue(const function<bool(int, int)> _compare): dq(), compare(_compare) {}

        int getFront() {
            return dq.front();
        }

        int popFront() {
            const auto result = dq.front();
            dq.pop_front();
            return result;
        }

        void pushNum(const int num) {
            while (!dq.empty() && compare(num, dq.back())) {
                dq.pop_back();
            }

            dq.push_back(num);
        }

        bool empty() {
            return dq.empty();
        }

    private:
        deque<int> dq;
        const function<bool(int, int)> compare;
    };

public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int n = nums.size();
        const auto _less = less<int>();
        const auto _bigger = greater<int>();
        MonotonicQueue maxQ(_bigger);
        MonotonicQueue minQ(_less);
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < n) {
            const int currNum = nums[right++];
            minQ.pushNum(currNum);
            maxQ.pushNum(currNum);

            while ((maxQ.getFront() - minQ.getFront()) > limit) {
                const int numGetEvicted = nums[left++];
                if (numGetEvicted == maxQ.getFront()) maxQ.popFront();
                if (numGetEvicted == minQ.getFront()) minQ.popFront();
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}