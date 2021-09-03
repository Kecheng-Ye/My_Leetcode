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
    int result = 0;
    
    // Time: O(n), Space: O(n)
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
                
        return result;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        result = (left + right > result) ? left + right : result;
                
        return max(left, right) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}