#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size < n - 1) return false;

        int remain = n;

        for(int i = 0; i < size && remain > 0; i++) {
            if(flowerbed[i] == 1) continue;

            bool left_valid = ((i - 1) >= 0) ? flowerbed[i - 1] == 0 : true;
            bool right_valid = ((i + 1) < size) ? flowerbed[i + 1] == 0 : true;

            if(left_valid && right_valid) {
                flowerbed[i] = 2;
                remain--;
            }
        }  

        return (remain <= 0);
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {1, 0, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(input, 2) << endl;
    return 0;
}
