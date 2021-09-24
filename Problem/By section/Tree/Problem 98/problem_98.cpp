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
    // Time: O(n), Space: O(logn)
    // bool isValidBST(TreeNode* root) {
    //     return isValidBST(root->left, root->val, ((long long)INT_MIN - 1)) && isValidBST(root->right, ((long long)INT_MAX + 1), root->val);
    // }
    
    // bool isValidBST(TreeNode* root, long long max, long long min) {
    //     if(!root) return true;
        
    //     if(root->val >= max || root->val <= min) {
    //         return false;
    //     }else{
            
    //         return isValidBST(root->left, root->val, min) && isValidBST(root->right, max, root->val);
    //     }
    // }


    // TreeNode *prev = nullptr; 
    // Time: O(n), Space: O(logn)
    // bool isValidBST(TreeNode* root) {
    //     if(!root) return true;
        
    //     if(!isValidBST(root->left)) return false;
    //     if(prev) {
    //         if(root->val <= prev->val) return false;
    //     }
    //     prev = root;
        
    //     if(!isValidBST(root->right)) return false;
        
    //     return true;
    // }

    // Time: O(n), Space: O(logn)
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *prev = nullptr; 
        
        while(!s.empty() || cur) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode *temp = s.top();
            s.pop();
            if(prev) {
                if(temp->val <= prev->val) return false;
            }
            prev = temp;
            cur = temp->right;
        }
        
        return true;
    }
};



int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}