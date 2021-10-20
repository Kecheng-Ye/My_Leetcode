#include <bits/stdc++.h>

using namespace std;

#define X point[0]
#define Y point[1] 
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x, y;
        int minArea = INT_MAX;

        for(auto &point: points) {
            if(x.count(X) && y.count(Y)) {
                for(auto &ty: x[X]) {
                    for(auto &tx: y[ty]) {
                         if(y[Y].count(tx)) minArea = min(minArea, abs(ty - Y) * abs(tx - X)); 
                    }
                }
            }
            
            if(minArea == 1) return 1;
            x[X].insert(Y), y[Y].insert(X);
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}