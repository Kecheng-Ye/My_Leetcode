#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
**/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        
        vector<int> result;
        result.push_back(root->val);
        left_boundary(root->left, result);
        if(!is_leaf(root)) add_leaf(root, result);
        right_boundary(root->right, result);
        
        return result;
    }
    
private:
    
    bool is_leaf(TreeNode *root) {
        return !root->left && !root->right;
    }
    
    void add_leaf(TreeNode *root, vector<int>& result) {
        if(!root) return;
        
        if(is_leaf(root)) {
            result.push_back(root->val);
            return;
        }
        
        add_leaf(root->left, result);
        add_leaf(root->right, result);
    }
    
    void left_boundary(TreeNode *root, vector<int>& result) {
        if(!root) return;
        
        TreeNode *temp = root;
        
        while(temp) {
            if(!is_leaf(temp)) result.push_back(temp->val);
            
            if(temp->left) {
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
    }
    
    void right_boundary(TreeNode *root, vector<int>& result) {
        if(!root) return;
        
        TreeNode *temp = root;
        stack<int> st;
        
        while(temp) {
            if(!is_leaf(temp)) st.push(temp->val);
            
            if(temp->right) {
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        
        while(st.size()) {
            result.push_back(st.top());
            st.pop();
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}