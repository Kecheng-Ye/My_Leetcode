#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy) {
            if(tx == ty) break;
            
            if(tx > ty) {
                if(ty > sy) {
                    tx %= ty;
                }else if(ty == sy) return ((tx - sx) % sy) == 0;
            }else{
                if(tx > sx) {
                    ty %= tx;
                }else if(tx == sx) return ((ty - sy) % sx) == 0;
            }
        }
        
        return tx == sx && ty == sy;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}