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
    // Time: O(n), Space: O(logn) if balanced else O(n)
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}