#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            const int front = arrays[i][0], back = arrays[i].back();

            max_distance = max(max_distance, abs(back - smallest));
            max_distance = max(max_distance, abs(biggest - front));
            smallest = min(smallest, front);
            biggest = max(biggest, back);
        }

        return max_distance;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}