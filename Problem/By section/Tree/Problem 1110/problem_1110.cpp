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
    // // Time: O(n), Space: O(n)
    // vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    //     if(!root) return {};
        
    //     unordered_set<int> del_set(to_delete.begin(), to_delete.end());
    //     vector<TreeNode*> result;
        
    //     if(!del_set.count(root->val)) result.push_back(root);
        
    //     traverse(root, del_set, result);
    //     return result;
    // }
    
    // void traverse(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& result) {
    //     if(!root) return;
        
    //     if(to_delete.count(root->val)) {
    //         if(root->left && !to_delete.count(root->left->val)) {
    //             result.push_back(root->left);
    //         }
            
    //         if(root->right && !to_delete.count(root->right->val)) {
    //             result.push_back(root->right);
    //         }
    //     }
        
    //     auto left = root->left;
    //     auto right = root->right;
        
    //     if(root->left && to_delete.count(root->left->val)) {
    //         root->left = nullptr;
    //     }
        
    //     if(root->right && to_delete.count(root->right->val)) {
    //         root->right = nullptr;
    //     }
        
    //     traverse(left, to_delete, result);
    //     traverse(right, to_delete, result);
    // }

    // Time: O(n), Space: O(n)
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        
        unordered_set<int> del_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        traverse(root, true, del_set, result);
        return result;
    }
    
    void traverse(TreeNode* root, bool parent_delete, unordered_set<int>& to_delete, vector<TreeNode*>& result) {
        if(!root) return;
        
        bool delete_this = to_delete.count(root->val);
        
        // if our parent has been deleted and current node is not deleted
        // the current node is the root of a new tree
        if(!delete_this && parent_delete) result.push_back(root);
        
        traverse(root->left, delete_this, to_delete, result);
        traverse(root->right, delete_this, to_delete, result);
        
        if(root->left && to_delete.count(root->left->val)) root->left = nullptr;
        if(root->right && to_delete.count(root->right->val)) root->right = nullptr;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}