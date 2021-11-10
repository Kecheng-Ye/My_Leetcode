#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet(): record(), lst(){
        
    }
    
    bool insert(int val) {
        if(record.count(val)) return false;
        
        record[val] = lst.size();
        lst.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!record.count(val)) return false;
        
        int old_idx = record[val];
        record[lst.back()] = old_idx;
        record.erase(val);
        lst[old_idx] = lst.back();
        lst.pop_back();
        return true;
    }
    
    int getRandom() {
        return lst[rand() % lst.size()];
    }
    
private:
    unordered_map<int, int> record;
    vector<int> lst;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}