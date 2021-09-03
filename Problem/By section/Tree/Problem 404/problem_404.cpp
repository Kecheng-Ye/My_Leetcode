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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        
        if(root->left && !root->left->left && !root->left->right) {
            ans += root->left->val;
            ans += sumOfLeftLeaves(root->right);
        }else{
            ans = sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
        }
            
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}