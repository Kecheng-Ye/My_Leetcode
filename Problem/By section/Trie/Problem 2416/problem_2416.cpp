#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int n = words.size();

        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            result[i] = trie.searchPrefix(words[i]);
        }

        return result;
    }

private:
    class Trie {
    public:
        Trie() {
            root = new TreeNode();
        }

        ~Trie() {
            delete root;
        }

        void insert(const string& s) {
            TreeNode *temp = root;

            for (const char c : s) {
                if (!(temp->children[c - 'a'])) {
                    temp->children[c - 'a'] = new TreeNode();
                }

                temp = temp->children[c - 'a'];
                temp->count++;
            }
            
        }

        int searchPrefix(const string& s) {
            TreeNode *temp = root;
            int result = 0;

            for (const char c : s) {
                if (!(temp->children[c - 'a'])) {
                    return -1;
                }

                temp = temp->children[c - 'a'];
                result += temp->count;
            }

            return result;
        }

    private:
        class TreeNode {
        public:
            TreeNode(): count(0) {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
            }

            ~TreeNode() {
                for (TreeNode* child : children) {
                    if (child) {
                        delete child;
                    }
                }
            }

            TreeNode* children[26];
            int count;
        };
    public:
        TreeNode *root;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}