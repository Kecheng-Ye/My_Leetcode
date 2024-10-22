#include <bits/stdc++.h>

using namespace std;

#define LIMIT (8)
#define INVALID (-1)

using DataNode = pair<int, int>;

class MyHashMap {
public:
    MyHashMap(): data(LIMIT, vector<DataNode>()) {
        
    }
    
    void put(int key, int value) {
        auto& targetBucket = data[key % LIMIT];

        for (int i = 0; i < targetBucket.size(); i++) {
            if (targetBucket[i].first == key) {
                targetBucket[i].second = value;
                return;
            }
        }

        targetBucket.emplace_back(key, value);
    }
    
    int get(int key) {
        auto& targetBucket = data[key % LIMIT];

        for (int i = 0; i < targetBucket.size(); i++) {
            if (targetBucket[i].first == key) {
                return targetBucket[i].second;
            }
        }

        return INVALID;
    }
    
    void remove(int key) {
        auto& targetBucket = data[key % LIMIT];

        for (int i = 0; i < targetBucket.size(); i++) {
            if (targetBucket[i].first == key) {
                targetBucket.erase(targetBucket.begin() + i);
                break;
            }
        }
    }

private:
    vector<vector<DataNode>> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char** argv) {
    
    return 0;
}