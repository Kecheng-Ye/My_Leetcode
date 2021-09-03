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
    int count = 0;
    int result;
    
    // Time: O(n), Space: O(n)
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        
        traverse(root, k);
        return result;
    }
    
    bool traverse(TreeNode* root, int k) {
        if(!root) return false;
        
        if(traverse(root->left, k)) return true;
        
        count++;
        if(count == k) {
            result = root->val;
            return true;
        }
        
        return traverse(root->right, k);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}