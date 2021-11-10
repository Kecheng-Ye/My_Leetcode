#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class Trie {
    public:
        Trie() {
            root = make_unique<TreeNode>();
        }
        
        void insert(const string& a) {
            TreeNode* temp = root.get();
            
            for(const auto& c : a) {
                if(!temp->children[c - 'a']) 
                    temp->children[c - 'a'] = new TreeNode();
                
                temp = temp->children[c - 'a'];
            }
            
            temp->is_end = true;
        }
        
        bool check_isconnect(const string& str, int start) {
            TreeNode* temp = root.get();
            int n = str.size();
            
            for(int i = start; i < n; i++) {
                if(!temp->children[str[i] - 'a']) return false;
                
                temp = temp->children[str[i] - 'a'];
                
                if(temp->is_end && (i + 1 == n || 
                   check_isconnect(str, i + 1))) return true; 
            }
            
            return false;
        }
        
    private:
        struct TreeNode {
            vector<TreeNode*> children;
            bool is_end;
            
            TreeNode() {
                children = vector<TreeNode*>(26, nullptr);
                is_end = false;
            }
            
            ~TreeNode() {
                for(TreeNode* node : children) {
                    if(node) delete node;
                }
            }
        };
        
        unique_ptr<TreeNode> root;
    };

    static bool compare(const string& a, const string& b) {
        return a.size() < b.size();
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        if(n <= 1) return {};
        
        sort(words.begin(), words.end(), compare);
        Trie trie;
        vector<string> result;
        
        for(const string& str : words) {
            if(trie.check_isconnect(str, 0)) {
                result.push_back(str);
            }else{
                trie.insert(str);
            }
        }
        
        return result;
    }
};


int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}