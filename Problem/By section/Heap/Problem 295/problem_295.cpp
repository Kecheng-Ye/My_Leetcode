#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    // Space: O(n)
    MedianFinder(): small_half(), bigger_half(), size(0) {
        
    }
    
    // Time: O(logn)
    void addNum(int num) {
        if(!size) {
            small_half.push(num);
        }else{
            if(num > small_half.top()) {
                bigger_half.push(num);
            }else{
                small_half.push(num);
            }

            if(abs((int)small_half.size() - (int)bigger_half.size()) >= 2) {
                balance();
            }   
        }
        
        size++;
    }
    
    // Time: O(logn)
    double findMedian() {
        if(size % 2 != 0) {
            return (small_half.size() > bigger_half.size()) ? small_half.top() : bigger_half.top();
        }else{
            if(small_half.size() != bigger_half.size()) {
                balance();
            }
            
            return (double)(small_half.top() + bigger_half.top()) / 2;
        }
    }
    
private:
    void balance() {
        if(small_half.size() > bigger_half.size()) {
            bigger_half.push(small_half.top());
            small_half.pop();
        }else{
            small_half.push(bigger_half.top());
            bigger_half.pop();
        }
    }
    
    priority_queue<int, vector<int>> small_half;                // first half of the arr, maintained by a max heap
    priority_queue<int, vector<int>, greater<int>> bigger_half; // second hald of the arr, maintained by a min heap
    int size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}