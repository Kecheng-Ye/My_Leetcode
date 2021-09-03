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
    // BFS approach
    // Time: O(n), Space: O(n)
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if(!temp) continue;
            TreeNode* left = temp->left;
            temp->left = temp->right;
            temp->right = left;
            
            q.push(temp->left);
            q.push(temp->right);
        }
        
        return root;
    }

    // Recursive approach
    // Time: O(n), Space: O(n)
    // TreeNode* invertTree(TreeNode* root) {
    //     if(!root) return nullptr;
        
    //     TreeNode* inverse_left = invertTree(root->left);
    //     TreeNode* inverse_right = invertTree(root->right);
        
    //     root->left = inverse_right;
    //     root->right = inverse_left;
        
    //     return root;
    // }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}