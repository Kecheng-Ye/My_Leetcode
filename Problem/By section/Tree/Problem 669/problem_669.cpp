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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) {
            return nullptr;
        }else if(root->val < low) {
            return trimBST(root->right, low, high);
        }else if(root->val > high) {
            return trimBST(root->left, low, high);
        }else{
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;   
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}