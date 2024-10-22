#include <bits/stdc++.h>

using namespace std;

#define MOD 1337
#define MODE_NUM(expr) ((expr) % MOD)

class Solution {
public:
    // Intuition: a ^ [1, 5, 4, 6] = (a ^ 6) * (a ^ [1, 5, 4]) ^ 10
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }

        int currDigit = b.back(); b.pop_back();
        int currPower = quickPower(a, currDigit);
        int restPower = quickPower(superPow(a, b), 10);
        return MODE_NUM(currPower * restPower);
    }

private:
    int quickPower(const int base, const int pow) {
        if (pow == 0) return 1;

        const int _base = MODE_NUM(base);

        if (pow % 2) {
            return MODE_NUM(_base * MODE_NUM(quickPower(_base, pow - 1)));
        } else {
            const int subPow = MODE_NUM(quickPower(_base, pow / 2));
            return MODE_NUM(subPow * subPow);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}