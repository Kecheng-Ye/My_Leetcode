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
    
    int sumNumbers(TreeNode* root) {
        result = 0;
        DFS(root, 0);
        return result;
    }
    
    void DFS(TreeNode* root, int val) {
        if(!root) {
            return;
        }
        
        val = val * 10 + root->val;
        
        if(!(root->left) && !(root->right)) {
            result += val;
            return;
        }
        
        DFS(root->left, val);
        DFS(root->right, val);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}