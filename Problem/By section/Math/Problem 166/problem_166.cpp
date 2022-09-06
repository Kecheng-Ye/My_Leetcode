#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Long division approach
    // When we get a same remainder, we know we've reached a recurring sequence
    // Need a hashmap to keep track all previous remainder
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string result;

        if ((numerator < 0) ^ (denominator < 0)) {
            result += '-';
        }

        long long _numerator = abs((long long) numerator);
        long long _denominator = abs((long long) denominator);
        unordered_map<long long, int> record;

        result += to_string(_numerator / _denominator);

        long long remainder = _numerator % _denominator;
        if (remainder == 0) return result;

        result += '.';

        while (remainder != 0) {
            if (record.count(remainder)) {
                int start_pos = record[remainder];
                result = result.substr(0, start_pos) + '(' + result.substr(start_pos, result.size() - start_pos) + ')';
                break;
            }

            record[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / _denominator);
            remainder %= _denominator;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
