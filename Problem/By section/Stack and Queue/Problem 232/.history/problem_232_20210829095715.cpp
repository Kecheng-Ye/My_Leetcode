#include <bits/stdc++.h>
#include <memory>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        a = stack<int>();
        b = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!a.empty()) {
            auto temp = a.top();
            a.pop();
            b.push(temp);
        }
        
        int result = b.top();
        b.pop();
        
        while(!b.empty()) {
            auto temp = b.top();
            b.pop();
            a.push(temp);
        }
        
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        while(!a.empty()) {
            auto temp = a.top();
            a.pop();
            b.push(temp);
        }
        
        int result = b.top();
        
        while(!b.empty()) {
            auto temp = b.top();
            b.pop();
            a.push(temp);
        }
        
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
    
private:
    stack<int> a;
    stack<int> b;
};

int main(int argc, char** argv) {
    // Solution s;

    return 0;
}