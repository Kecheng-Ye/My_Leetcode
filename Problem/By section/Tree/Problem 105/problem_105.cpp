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
    int pre_idx;
    
    // Time: O(n), Space: O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 1) return new TreeNode(preorder[0]);
        
        unordered_map<int, int> record;
        
        for(int i = 0; i < n; i++) {
            record[inorder[i]] = i;
        }
        
        pre_idx = -1;
        
        return helper(preorder, record, 0, n - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& record, int left, int right) {
        if(left > right) return nullptr;
        
        pre_idx++;
        int piviot = record[preorder[pre_idx]];
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        if(left == right) return root;
        
        root->left = helper(preorder, record, left, piviot - 1);
        root->right = helper(preorder, record, piviot + 1, right);
            
        return root;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}