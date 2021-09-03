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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        
        if(!root || !subRoot) return false;
        
        return isSubtree_strick(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }
    
    // Time: O(NlogN), Space: O(NlogN)
    bool isSubtree_strick(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;    
        }else if(!root || !subRoot) {
            return false;
        }else if(root->val != subRoot->val) {
            return false;
        }else{
            return isSubtree_strick(root->left, subRoot->left) && isSubtree_strick(root->right, subRoot->right);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}