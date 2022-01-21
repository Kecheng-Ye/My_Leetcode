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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        int min_val = min(p->val, q->val);
        int max_val = max(p->val, q->val);
        
        if(root->val > max_val) return lowestCommonAncestor(root->left, p, q);
        if(root->val < min_val) return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}