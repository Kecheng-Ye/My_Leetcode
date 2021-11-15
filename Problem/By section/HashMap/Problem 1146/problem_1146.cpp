#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
    unordered_map<int, map<int, int>> A;
    int snap_no = 0;
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        A[index][snap_no] = val;
    }
    
    int snap() {
        return snap_no++;
    }
    
    int get(int index, int snap_id) {
        //returns value (snap id) from MAP greater than snap_id
        auto it = A[index].upper_bound(snap_id);
        //If no value greater, i.e. iterator still pointing at start = return 0, else return the prev of upperbound-> that can equal or less than snap_id we want ->second (value)
        return (it == begin(A[index])) ? 0 : prev(it)->second; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}