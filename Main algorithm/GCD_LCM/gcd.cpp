#include <bits/stdc++.h>

using namespace std;

class Algorithm{
public:
    int gcd_euclidan(int x, int y){
        if (x < y) return gcd_euclidan(y, x);

        return y == 0 ? x : gcd_euclidan(y, x % y);
    }

    int gcd_shift(int x, int y) {
        if(x < y) return gcd_shift(y, x);

        if(y == 0) return x;

        int isX_Even = !(x % 2), isY_Even = !(y % 2);
        if(isX_Even && isY_Even) {
            return 2 * gcd_shift(x >> 1, y >> 1);
        }else if(!isX_Even && isY_Even) {
            return gcd_shift(x, y >> 1);
        }else if(isX_Even && !isY_Even) {
            return gcd_shift(x >> 1, y);
        }else{
            return gcd_shift(x - y, y);
        }
    }
};

int main(int argc, char** argv) {
    Algorithm s;
    cout << s.gcd_shift(28, 4) << endl;
    return 0;
}