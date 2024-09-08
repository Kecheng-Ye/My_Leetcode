#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int compress(vector<char>& chars) {
        const int n = chars.size();
        if (n == 1) return 1;

        int result = 0;
        const auto countSingleChar = [&](const int startIdx) -> int {
            int endIdx = startIdx;
            while (endIdx < n && chars[endIdx] == chars[startIdx]) {
                endIdx++;
            }
            
            int num = endIdx - startIdx;
            if (num > 1) {
                int prev = result;
                while (num > 0) {
                    chars[result++] = (char)(num % 10 + '0');
                    num /= 10;
                }
                reverse(chars.begin() + prev, chars.begin() + result);
            }

            return endIdx;
        };

        int i = 0;
        while (i < n) {
            chars[result++] = chars[i];
            i = countSingleChar(i);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}