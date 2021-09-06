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
    int post_idx;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        
        int n = inorder.size();
        post_idx = n - 1;
        for(int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
              
        return buildTree(inorder, postorder, inorder_map, 0, n - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorder_map, int start, int end) {
        if(start > end) return nullptr;
        
        int mid = inorder_map[postorder[post_idx--]];
        TreeNode* root = new TreeNode(inorder[mid]);
        
        root->right = buildTree(inorder, postorder, inorder_map, mid + 1, end);
        root->left = buildTree(inorder, postorder, inorder_map, start, mid - 1);
        
        return root;
        
    }
    

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}