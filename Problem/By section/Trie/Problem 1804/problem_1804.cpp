#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *temp = root;
        
        for(const char c : word) {
            if(!(temp->children[c - 'a'])) {
                temp->children[c - 'a'] = new node();
            }
            
            temp = temp->children[c - 'a'];
            (temp->count)++;
        }
        
        temp->end_words++;
    }
    
    int countWordsEqualTo(string word) {
        node *temp = root;
        
        for(const char c : word) {
            if(!(temp->children[c - 'a'])) {
                return false;
            }
            
            temp = temp->children[c - 'a'];
        }
        
        return temp->end_words;
    }
    
    int countWordsStartingWith(string prefix) {
        node *temp = root;
        
        for(const char c : prefix) {
            if(!(temp->children[c - 'a'])) {
                return false;
            }
            
            temp = temp->children[c - 'a'];
        }
        
        return temp->count;
    }
    
    void erase(string word) {
        node *temp = root;
        
        for(const char c : word) {
            node* child = temp->children[c - 'a'];
            if(--child->count == 0) {
                delete child;
                temp->children[c - 'a'] = nullptr;
                return;
            }
            temp = child;
        }
        
        temp->end_words--;
    }
    
private:
    // we need two counts here
    // end_words represent how many words ends here
    // count represents how many words pass here
    struct node {
        vector<node*> children;
        int end_words;
        int count;
        
        node(): children(26, nullptr), count(0), end_words(0) {};
        ~node() {
            for(const node* child : children) {
                if(child)
                    delete child;
            }
        }
    };
    
    
    node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}