#include <bits/stdc++.h>

using namespace std;

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity): 
        mtx(), consumer_cv(), producer_cv(), 
        data(capacity), _size(0), limit(capacity), 
        startPtr(0), endPtr(0) 
    {
        
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mtx);
        consumer_cv.wait(lock, [&]{ return (_size < limit); } );
        data[endPtr++ % limit] = element;
        _size++;
        lock.unlock();
        producer_cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(mtx);
        producer_cv.wait(lock, [&]{ return (_size > 0); } );
        int result = data[startPtr++ % limit];
        _size--;
        lock.unlock();
        consumer_cv.notify_all();
        return result;
    }
    
    int size() {
        unique_lock<mutex> lock(mtx);
        const int result = _size;
        lock.unlock();

        return result;
    }

private:
    mutex mtx;
    condition_variable consumer_cv;
    condition_variable producer_cv;
    vector<int> data;
    int _size;
    const int limit;
    int startPtr;
    int endPtr;
};

int main(int argc, char** argv) {
    return 0;
}