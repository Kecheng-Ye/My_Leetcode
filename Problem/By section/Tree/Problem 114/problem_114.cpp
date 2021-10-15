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
    void flatten(TreeNode* root) {
        TreeNode *temp;
        flattern_helper(root, &temp);
    }
    
    void flattern_helper(TreeNode* root, TreeNode **result) {
        if(!root) {
            *result = nullptr;
            return;
        }
        
        if(!(root->right) && !(root->left)) {
            *result = root;
            return;
        }

        TreeNode *end_left, *end_right;
        
        flattern_helper(root->left, &end_left);
        flattern_helper(root->right, &end_right);
        TreeNode *cur_right = root->right;
        
        if(end_left) {
            root->right = root->left;
            end_left->right = cur_right;
            root->left = nullptr;
        }
        
        if(!end_right) {
            *result = end_left;
        }else{
            *result = end_right;   
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}