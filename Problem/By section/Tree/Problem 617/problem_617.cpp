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
    // Time: O(n), Space: O(n)
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return nullptr;
        }else if(!root1) {
            return root2;
        }else if(!root2) {
            return root1;
        }else{
            TreeNode* new_root = new TreeNode(root1->val + root2->val);
            new_root->left = mergeTrees(root1->left, root2->left);
            new_root->right = mergeTrees(root1->right, root2->right);
            return new_root;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}