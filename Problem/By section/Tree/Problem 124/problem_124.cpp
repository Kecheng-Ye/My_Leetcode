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
    int _max = INT_MIN;  
    
    int maxPathSum(TreeNode* root) {
        DFS(root);
        
        return _max;
    }
    
    int DFS(TreeNode* root) {
        if(!root) return 0;
        
        int left = DFS(root->left);
        left = (left < 0) ? 0 : left;
        int right = DFS(root->right);
        right = (right < 0) ? 0 : right;
        
        _max = max(root->val + left + right, _max);
        return root->val + max(left, right);
    }
  
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}