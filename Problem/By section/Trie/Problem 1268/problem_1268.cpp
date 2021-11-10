#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class Prefix_Tree {
    public:
        Prefix_Tree() {
            root = make_unique<TreeNode>();
        }
        
        void insert(const string& word) {
            TreeNode* temp = root.get(); 
            for(const char c : word) {
                if(!temp->children[c - 'a']) {
                    temp->children[c - 'a'] = new TreeNode();
                }
                
                temp = temp->children[c - 'a'];
            }
            
            temp->is_end = true;
        }
        
        vector<string> search(const string& word) {
            vector<string> result;
            
            TreeNode* temp = find(word); 
            if(!temp) return result;
            reach_limit = false;
            string str = word;
            DFS(temp, result, str);
            return result;
        }
        
        
    private:
        struct TreeNode {
        public:
            vector<TreeNode*> children;
            bool is_end;
            
            TreeNode(): is_end(false), children(26, nullptr) {};
            
            ~TreeNode() {
                for(TreeNode* child : children) {
                    if(child) delete child;
                }
            }
            
            TreeNode* operator[](const int a) {
                return children[a];
            }
        };
        
        unique_ptr<TreeNode> root;
        
        TreeNode* find(const string& input) {
            TreeNode* temp = root.get(); 
            for(const char c : input) {
                if(!(temp->children[c - 'a'])) return nullptr;
                
                temp = temp->children[c - 'a'];
            }
            
            return temp;
        }
        
        bool reach_limit;
        
        void DFS(TreeNode* root, vector<string>& result, string& temp) {
            if(root->is_end) {
                result.push_back(string(temp));
            }
            
            if(result.size() == 3) {
                reach_limit = true;
                return;
            }
            
            for(int i = 0; i < 26; i++) {
                if(root->children[i]) {
                    string new_str = temp + (char)('a' + i);
                    DFS(root->children[i], result, new_str);
                    if(reach_limit) return;
                }
            }
        }
    };
    
    const int limit = 3;
    
public:
    // Let, m = searchWord length, n = products array length, p = largest product word length
    // Time: O(p * n) + O(m ^ 2), Space: O(np)
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Prefix_Tree trie;
        
        for(const auto& str : products) {
            trie.insert(str);
        }
        
        vector<vector<string>> result;
        int n = searchWord.size();
        
        for(int i = 0; i < n; i++) {
            result.push_back(trie.search(searchWord.substr(0, i + 1)));
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}