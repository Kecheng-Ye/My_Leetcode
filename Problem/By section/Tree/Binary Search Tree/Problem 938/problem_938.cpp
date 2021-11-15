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
    int result;
    
    // Time: O(n), Space: O(logn)
    int rangeSumBST(TreeNode* root, int low, int high) {
        result = 0;
        
        traverse(root, low, high);
        
        return result;
    }
    
    void traverse(TreeNode* root, int low, int high) {
        if(!root)
            return;
        
        if(root->val <= high && root->val >= low) {
            result += root->val;
            traverse(root->left, low, high);
            traverse(root->right, low, high);
        }else if(root->val > high) {
            traverse(root->left, low, high);
        }else if(root->val < low) {
            traverse(root->right, low, high);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}