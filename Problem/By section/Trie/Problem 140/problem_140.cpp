#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n!), Space: O(m)
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        
        for(const auto& word : wordDict) {
            trie.insert(word);
        }
        
        vector<string> result;
        string single_result;
        backTrack(result, single_result, s, 0, trie);
        return result;
    }

private:
    class Trie{
    public:
        Trie() {
            root = new node();
        }
        
        ~Trie() {
            delete root;
        }
        
        void insert(const string& word) {
            node* temp = root;
            
            for(char c : word) {
                if(!temp->children[(c - 'a')]) {
                    temp->children[(c - 'a')] = new node();
                }
                
                temp = temp->children[(c - 'a')];
            }
            
            temp->isEnd = true;
        }
        
        class node {
        public:
            vector<node*> children;
            bool isEnd;

            node(): children(26, nullptr), isEnd(false) {}
            ~node() {
                for(int i = 0; i < 26; i++) {
                    if(children[i])
                        delete children[i];
                }
            }
        };        
        
        node* root;
    };
    
    void backTrack(vector<string>& result, string& single_result, string& s, int index, Trie& trie) {
        if(index == s.size()) {
            result.push_back(string(single_result.begin(), single_result.end() - 1));
        }else{
            Trie::node* temp = trie.root;
            int n = s.size();
            for(int i = index; i < n; i++) {
                char target = s[i];
                
                if(!temp->children[(target - 'a')]) break;
                
                if(temp->children[(target - 'a')]->isEnd) {
                    string new_str = single_result + string(s.begin() + index, s.begin() + i + 1) + " ";
                    backTrack(result, new_str, s, i + 1, trie);
                }
                
                temp = temp->children[(target - 'a')];
            }
        }
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}