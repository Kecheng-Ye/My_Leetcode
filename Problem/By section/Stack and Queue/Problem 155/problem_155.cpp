#include <bits/stdc++.h>

using namespace std;

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
        
//     }
//     Time: O(1), Space: O(1)
//     void push(int val) {
//         int cur_min;
//         if(s.empty()){
//             cur_min = INT_MAX;
//         }else{
//             cur_min = s.top().second;
//         } 
//         cur_min = min(val, cur_min);
//         s.push(make_pair(val, cur_min));
//     }
//     Time: O(1), Space: O(1)    
//     void pop() {
//         s.pop();
//     }
//     Time: O(1), Space: O(1)    
//     int top() {
//         return s.top().first;
//     }
//     Time: O(1), Space: O(1)    
//     int getMin() {
//         return s.top().second;
//     }
    
// private:
//            cur_val, cur_min
//     stack<pair<int, int>> s;
// };

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    // Time: O(1), Space: O(1)
    void push(int val) {
        int cur_min;
        if(data.empty()) {
            cur_min = INT_MAX;
        }else{
            cur_min = getMin();
        }
        
        if(data.empty() || val < cur_min) {
            min.push({val, 1});
        }else if(val == cur_min) {
            min.top().second++;
        }
        
        data.push(val);
    }
    // Time: O(1), Space: O(1)
    void pop() {
        int val = top();
        
        if(val == getMin()) {
            if(min.top().second == 1) {
                min.pop();
            }else{
                min.top().second--;
            }
        }
        
        data.pop();
    }
    // Time: O(1), Space: O(1)
    int top() {
        return data.top();
    }
    // Time: O(1), Space: O(1)
    int getMin() {
        return min.top().first;
    }
    
private:
    stack<int> data; // all the stored data
    stack<pair<int, int>> min; // min value with its frequency
};

int main(int argc, char** argv) {
    
    return 0;
}