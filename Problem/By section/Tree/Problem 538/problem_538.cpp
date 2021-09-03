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
    TreeNode* convertBST(TreeNode* root) {
        int pre_sum = 0;
        traverse(root, pre_sum);
        return root;
    }
    
    void traverse(TreeNode* root, int& pre_sum) {
        if(!root) return;
        traverse(root->right, pre_sum);
        root->val = (pre_sum += root->val);
        traverse(root->left, pre_sum);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}