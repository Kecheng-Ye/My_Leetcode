#include <bits/stdc++.h>

using namespace std;

class MaxStack {
public:
    MaxStack(): _lst(), _map() {
        
    }
    
    // Time: O(logn)
    void push(int x) {
        _lst.push_back(x); // O(1)
        _map[x].push_back(--_lst.end()); // O(logn)
    }
    
    // Time: O(logn)
    int pop() {
        int valueToEvict = top(); // O(1)
        _map[valueToEvict].pop_back(); // O(logn + 1)
        if (_map[valueToEvict].size() == 0) {
            _map.erase(valueToEvict);  // O(logn)
        }
        _lst.pop_back();  // O(1)
        return valueToEvict;
    }
    
    // Time: O(1)
    int top() {
        return _lst.back();
    }
    
    // Time: O(logn)
    int peekMax() {
        return _map.rbegin()->first;
    }
    
    // Time: O(logn)
    int popMax() {
        auto& lstToEvict = _map.rbegin()->second; // O(logn)
        auto iteratorToBeEvict = lstToEvict.back(); // O(1)
        const int valueToEvict = *(iteratorToBeEvict); // O(1)

        lstToEvict.pop_back(); // O(1)
        _lst.erase(iteratorToBeEvict); // O(1)
        if (lstToEvict.size() == 0) {
            _map.erase(valueToEvict); // O(logn)
        }
        return valueToEvict;
    }

private:
    list<int> _lst;
    map<int, list<list<int>::iterator>> _map;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main(int argc, char** argv) {
    return 0;
}