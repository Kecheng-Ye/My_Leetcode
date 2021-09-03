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
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced_helper(root, height);
    }

    // bottom up recursion
    // carry both balance situation and height information
    bool isBalanced_helper(TreeNode* root, int& height) {
        if(!root) {
            height = 0;
            return true;
        }
        
        int left, right;
        if(isBalanced_helper(root->left, left) &&
           isBalanced_helper(root->right, right) && 
           abs(left - right) < 2) {
            // important here, set up the height for upper level use
            height = max(left, right) + 1;
            return true;
        }
        
        return false;
        
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}