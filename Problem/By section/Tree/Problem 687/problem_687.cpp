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
    // Time: O(NlogN), Space: O(NlogN)
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int result = longestUnivaluePath_single_path(root->left, root->val) + longestUnivaluePath_single_path(root->right, root->val);
        result = max(result, longestUnivaluePath(root->left));
        result = max(result, longestUnivaluePath(root->right));
        
        return result;
    }
    
    int longestUnivaluePath_single_path(TreeNode* root, int val) {
        if(!root || root->val != val) return 0;
        
        return 1 + max(longestUnivaluePath_single_path(root->left, val), longestUnivaluePath_single_path(root->right, val));
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}