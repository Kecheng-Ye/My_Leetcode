#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x11 = max(ax1, bx1);
        int x22 = min(ax2, bx2);
        int y11 = max(ay1, by1);
        int y22 = min(ay2, by2);
        
        int horizontal = max(0, x22 - x11);
        int vertical = max(0, y22 - y11);
            
        int area_1 = (ax2 - ax1) * (ay2 - ay1);
        int area_2 = (bx2 - bx1) * (by2 - by1);
        
        return area_1 + area_2 - horizontal * vertical;
        
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}