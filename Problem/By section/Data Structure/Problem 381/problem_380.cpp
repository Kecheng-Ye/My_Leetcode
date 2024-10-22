#include <bits/stdc++.h>

using namespace std;

class RandomizedCollection {
public:
    RandomizedCollection(): record(), lst(){
        
    }
    
    bool insert(int val) {
        bool hasMet = record.count(val);
        
        record[val].insert(lst.size());
        lst.push_back(val);
        
        return !hasMet;
    }
    
    bool remove(int val) {
        if(!record.count(val)) return false;
        
        int old_idx = *(record[val].rbegin());
        auto& valueIdxs = record[lst.back()];
        auto& valueToBeRemovedIdxs = record[val];
        
        valueIdxs.erase(--valueIdxs.end());
        valueIdxs.insert(old_idx);
        
        valueToBeRemovedIdxs.erase(--valueToBeRemovedIdxs.end());

        swap(lst.back(), lst[old_idx]);
        lst.pop_back();
        
        if (record[val].empty()) record.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return lst[rand() % lst.size()];
    }
    
private:
    unordered_map<int, set<int>> record;  // key -> sorted idx list
    vector<int> lst;                      // real data
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}