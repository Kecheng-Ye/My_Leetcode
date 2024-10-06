#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size): lst(size), sum(0), len(0), size(size) {
        
    }
    
    double next(int val) {
        sum += val;
        len++;
        
        if(len > size) {
            sum -= lst[len % size];
        }
        
        
        lst[len % size] = val;
        return (double)sum / (min(size, len));
    }
    
private:
    vector<int> lst;
    int sum;
    int len;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}