#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    WordDictionary(): trie() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
    
private:
    struct node {
        vector<node*> children;
        bool is_end;
        
        node(): children(26, nullptr), is_end(false) {};
        
        ~node() {
            for(int i = 0; i < 26; i++) {
                if(children[i]) delete children[i];
            }
        }
    };
    
    class Trie{
    public:
        Trie() {
            root = new node();
        }
        
        ~Trie() {
            delete root;
        }
        
        void insert(string& s) {
            node* temp = root;
            
            for(char c : s) {
                if(!temp->children[(c - 'a')]) {
                    temp->children[(c - 'a')] = new node();
                }
                
                temp = temp->children[(c - 'a')];
            }
            
            temp->is_end = true;
        }
        
        bool search(string& pattern) {
            node* temp = root;
            return search_helper(temp, pattern, 0);
        }
        
    private:
        node* root;
        
        bool search_helper(node* cur, string& pattern, int idx) {
            if(idx == pattern.size()) 
                return cur->is_end;
            
            if(pattern[idx] == '.') {
                for(int i = 0; i < 26; i++) {
                    if(cur->children[i] && search_helper(cur->children[i], pattern, idx + 1)) return true;
                }
            }else{
                int target_char = pattern[idx] - 'a';
                
                if(cur->children[target_char] && search_helper(cur->children[target_char], pattern, idx + 1)) return true;
            }
            
            return false;
        }
    };
    
    Trie trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char** argv) {
    
    return 0;
}