#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    // Digits         Largest         Value
    //   1               9               81
    //   2               99              162
    //   3               999             243
    //   4               9999            324
    //   13              99...99         1053
    // For a number with 3 digits, it's impossible for it to ever go larger than 243. This means it will have to either get stuck in a cycle below 243 or go down to 1. Numbers with 4 or more digits will always lose a digit at each step until they are down to 3 digits.                            
    bool isHappy(int n) {
        unordered_set<int> isVisited;

        const auto getNext = [](const int i) {
            int digitSum = 0;
            int temp = i;
            while (temp > 0) {
                digitSum += pow(temp % 10, 2);
                temp /= 10;
            }
            return digitSum;
        };

        while (!isVisited.count(n)) {
            isVisited.insert(n);
            const int nextNum = getNext(n);
            if (nextNum == 1) return true;
            n = nextNum;
        }

        return false;

    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}