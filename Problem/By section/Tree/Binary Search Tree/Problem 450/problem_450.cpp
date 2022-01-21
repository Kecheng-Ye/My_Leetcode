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
    // Time: O(logn), Space: O(logn)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(root->val == key) {
            if(!root->left && !root->right) {
                return nullptr;
            }else if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }else{
                TreeNode *biggest_min = root->left;
                while(biggest_min->right) {
                    biggest_min = biggest_min->right;
                }
                
                root->val = biggest_min->val;
                root->left = deleteNode(root->left, biggest_min->val);
            }
            
            return root;
        }else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}