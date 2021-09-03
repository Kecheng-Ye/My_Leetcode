#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        a = queue<int>();
        b = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(a.size() > 1) {
            auto temp = a.front();
            a.pop();
            b.push(temp);
        }
        
        int result = a.front();
        a.pop();
        
        while(!b.empty()) {
            auto temp = b.front();
            b.pop();
            a.push(temp);
        }
        
        return result;
    }
    
    /** Get the top element. */
    int top() {
        while(a.size() > 1) {
            auto temp = a.front();
            a.pop();
            b.push(temp);
        }
        
        int result = a.front();
        a.pop();
        b.push(result);
        
        while(!b.empty()) {
            auto temp = b.front();
            b.pop();
            a.push(temp);
        }
        
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }

private:
    queue<int> a;
    queue<int> b;
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}