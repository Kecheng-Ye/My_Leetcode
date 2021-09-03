#include <bits/stdc++.h>
#include <memory>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = make_unique<TreeNode>();
    }
    
    /** Inserts a word into the trie. */
    // Time: O(len(word))
    void insert(string word) {
        TreeNode* temp = root.get();
        for(const char c : word) {
            if(!temp->children[c - 'a']) {
                temp->children[c- 'a'] = new TreeNode();
            }
            temp = temp->children[c- 'a'];
        }
        temp->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    // Time: O(len(word))
    bool search(string word) {
        TreeNode* result = find(word);
        return result && result->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    // Time: O(len(word))
    bool startsWith(string prefix) {
        return find(prefix);
    }
    
private:
    struct TreeNode{
        vector<TreeNode*> children;
        bool is_end;
        
        TreeNode(): is_end(false), children(26, nullptr){}
        
        ~TreeNode() {
            for(TreeNode* node : children) {
                if(node) delete node;
            }
        }
    };
    
    unique_ptr<TreeNode> root;
    
    TreeNode* find(string word) {
        TreeNode* temp = root.get();
        for(const char c : word) {
            if(!temp->children[c - 'a']) {
                return nullptr;
            }
            temp = temp->children[c - 'a'];
        }
        
        return temp;
    }
};

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}