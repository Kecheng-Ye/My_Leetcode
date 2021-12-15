#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> new_cards(4);
        for(int i = 0; i < 4; i++) {
            new_cards[i] = static_cast<double>(cards[i]);
        }
        
        return helper(new_cards);
    }
    // 1 4 2 3
    // 4 2 3
    // 4 6
    // 24
    bool helper(vector<double>& left) {
        int n = left.size();
        if(n == 1 && abs(left[0] - 24.0) < 1e-5) return true;
        
        vector<double> new_left(n - 1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                for(int k = 0, index = 0; k < n; k++) {
                    if(k != i && k != j) {
                        new_left[index++] = left[k];
                    }
                }
                
                for(const auto& num : operations(left[i], left[j])) {
                    new_left[n - 2] = num;
                    if(helper(new_left)) return true;
                }
            }
        }
        
        return false;
    }
    
    vector<double> operations(double i, double j) {
        return {i + j, i - j, i * j, i / j, j - i, j / i};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}