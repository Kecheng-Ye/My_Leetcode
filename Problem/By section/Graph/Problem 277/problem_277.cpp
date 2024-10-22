#include <bits/stdc++.h>

using namespace std;

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int potentialCelebrity = 0;

        for (int i = 1; i < n; i++) {
            potentialCelebrity = knows(potentialCelebrity, i) ? i : potentialCelebrity;
        }

        for (int i = 0; i < n; i++) {
            if (i == potentialCelebrity) continue;

            if (knows(potentialCelebrity, i) || !knows(i, potentialCelebrity)) {
                return -1;
            }
        }

        return potentialCelebrity;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}