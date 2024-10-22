#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(maxSum)), Space: O(1)
    int maxValue(int n, int index, int maxSum) {
        long long i = 1, j = maxSum + 1;

        while (i < j) {
            const long long mid = i + (j - i) / 2;
            const long long sumResult = trySum(n, index, mid);

            if (sumResult > maxSum) {
                j = mid;
            } else if (sumResult == maxSum) {
                i = mid + 1;
            } else {
                i = mid + 1;
            }
        }

        return i - 1;
    }

    long long trySum(int n, int index, long long num) {
        long long sum = num;
        long long temp = num;
        int i = index;
        
        if (i <= (num - 1)) {
            const long long start = num - 1;
            const long long end = num - 1 - i + 1;
            sum += (start + end) * (start - end + 1) / 2;
        } else {
            const long long start = num - 1;
            const long long end = 1;
            sum += (start + end) * (start - end + 1) / 2;
            sum += (i - (start - end + 1));
        }


        if ((n - i - 1) <= (num - 1)) {
            const long long start = num - 1;
            const long long end = num - 1 - (n - i - 1) + 1;
            sum += (start + end) * (start - end + 1) / 2;
        } else {
            const long long start = num - 1;
            const long long end = 1;
            sum += (start + end) * (start - end + 1) / 2;
            sum += ((n - i - 1) - (start - end + 1));
        }

        return sum;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}