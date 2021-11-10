#include <bits/stdc++.h>

using namespace std;

// Author: Huahua
// Running time: 89 ms (beats 96.3%)
 
struct CacheNode {
    int key;
    int value;
    int freq;
    // pointer to the node in the list
    list<int>::const_iterator it;
};
 
class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_freq_(0) {}
    
    int get(int key) {
        auto it = n_.find(key);
        if (it == n_.cend()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) return;
        
        auto it = n_.find(key);
        if (it != n_.cend()) {
            // Key already exists, update the value and touch it
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if (n_.size() == capacity_) {
            // No capacity, need to remove one entry that
            // 1. has the lowest freq
            // 2. least recently used if there are multiple ones
            
            // Step 1: remove the element from min_freq_ list
            const int key_to_evict = l_[min_freq_].back();
            l_[min_freq_].pop_back();
            
            // Step 2: remove the key from cache
            n_.erase(key_to_evict);
        }
        
        // We know new item has freq of 1, thus set min_freq to 1
        const int freq = 1;
        min_freq_ = freq;
        
        // Add the key to the freq list
        l_[freq].push_front(key);
        
        // Create a new node
        n_[key] = {key, value, freq, l_[freq].cbegin()};
    }
private:
    void touch(CacheNode& node) {
        // Step 1: update the frequency
        const int prev_freq = node.freq;
        const int freq = ++(node.freq);
        
        // Step 2: remove the entry from old freq list
        l_[prev_freq].erase(node.it);
        
        if (l_[prev_freq].empty() && prev_freq == min_freq_) {
            // Delete the list
            l_.erase(prev_freq);
            
            // Increase the min freq
            ++min_freq_;
        }
        
        // Step 4: insert the key into the front of the new freq list
        l_[freq].push_front(node.key);
        
        // Step 5: update the pointer
        node.it = l_[freq].cbegin();
    }
    
    int capacity_;
    int min_freq_;
    
    // key -> CacheNode
    unordered_map<int, CacheNode> n_;
    
    // freq -> keys with freq
    unordered_map<int, list<int>> l_;
};

int main(int argc, char** argv) {
    return 0;
}