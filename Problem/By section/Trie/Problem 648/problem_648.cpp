#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // n = len(dictionary), k = avg(vocab), m = len(sentence)
    // Time: O(nk + m), Space: O(nk + m)
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& vocab : dictionary) {
            trie.insert(vocab);
        }

        string result;
        int idx = 0;
        while (idx < sentence.size()) {
            const int start = idx;
            while (idx < sentence.size() && sentence[idx] != ' ') {
                idx++;
            } 
            result += trie.search(sentence.substr(start, idx - start)) + " ";
            idx++;
        }
        result.pop_back();
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
        

        // Time: O(len(word)), Space: O(1)
        string search(string word) {
            node* temp = root;
            int idx = 0;

            while (idx < word.size()) {
                const char c = word[idx];

                if(!temp->children[c - 'a']) {
                    return word;
                }
                temp = temp->children[c - 'a'];
                
                if (temp->isEnd) break; 
                
                idx++;
            }
            return word.substr(0, idx + 1);
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
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}