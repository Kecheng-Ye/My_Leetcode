#include <bits/stdc++.h>

using namespace std;

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
        
//     }
    
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
    
//     void pop() {
//         s.pop();
//     }
    
//     int top() {
//         return s.top().first;
//     }
    
//     int getMin() {
//         return s.top().second;
//     }
    
// private:
//     stack<pair<int, int>> s;
// };

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
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
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top().first;
    }
    
private:
    stack<int> data;
    stack<pair<int, int>> min;
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}