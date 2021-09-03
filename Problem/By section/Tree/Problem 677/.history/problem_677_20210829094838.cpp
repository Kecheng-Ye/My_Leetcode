#include <bits/stdc++.h>

using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = make_unique<TrieNode>();
        dict = unordered_map<string, int>();
    }
    
    void insert(string key, int val) {
        int diff = val - dict[key];
        TrieNode* temp = root.get();
        
        for(const char c : key) {
            if(!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new TrieNode();
            }
            
            temp = temp->children[c - 'a'];
            temp->sum += diff;
        }
        
        dict[key] = val;
        
    }
    
    int sum(string prefix) {
        TrieNode* temp = root.get();
        
        for(const char c : prefix) {
            if(!temp->children[c - 'a']) return 0;
            temp = temp->children[c - 'a'];
        }
        
        return temp->sum;
    }
    
    
private:
    unordered_map<string, int> dict;
    
    struct TrieNode {
        vector<TrieNode*> children;
        int sum;
        
        TrieNode() : children(26, nullptr), sum(0){}
        
        TrieNode(int val) : children(26, nullptr), sum(val){}
        
        ~TrieNode() {
            for(auto child : children) {
                if(child) delete child;
            }
        }
    };
    
    unique_ptr<TrieNode> root;
};


int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}