#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int countPrimes(int n) {
        if(n <= 1) return 0;

        vector<bool> record(n - 1, false);
        record[0] = true;
        int result = 0;

        for(int i = 2; i <= sqrt(n); i++) {
            if(record[i - 1]) continue;

            for(int j = i * i; j < n; j += i) {
                if(!record[j - 1]) { // avoid repetition
                    record[j - 1] = true;
                    result ++;
                }
            }
        }

        return n - 2 - result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.countPrimes(48399) << endl;
    return 0;
}