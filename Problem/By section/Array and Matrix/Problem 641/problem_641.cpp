#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k): limit(k), container(k, -1), head(0), tail(k - 1), size(0) {
        
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        head = toValidIdx(head - 1);
        container[head] = value;

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        tail = toValidIdx(tail + 1);
        container[tail] = value;

        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        container[head] = -1;
        head = toValidIdx(head + 1);

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        container[tail] = -1;
        tail = toValidIdx(tail - 1);

        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return container[head];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return container[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size >= limit;
    }

private:
    inline int toValidIdx(int target) {
        if (target >= limit) {
            return (target % limit);
        } else if (target < 0) {
            return (target + limit) % limit;
        } else {
            return target;
        }
    }

    vector<int> container;
    int head;
    int tail;
    int size;
    int limit;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(int argc, char** argv) {
    return 0;
}