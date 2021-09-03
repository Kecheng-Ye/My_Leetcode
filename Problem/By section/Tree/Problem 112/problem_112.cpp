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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        targetSum -= root->val;
        
        if(targetSum == 0 && !root->left && !root->right) return true;
    
        
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode a;
    cout << &a << " " << &(a.val) << endl;
    return 0;
}