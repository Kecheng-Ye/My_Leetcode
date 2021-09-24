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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        DFS(root, result, 0);
        return result;
    }
    
    void DFS(TreeNode* root, vector<int>& lst, int level) {
        if(!root) return;
        
        if(level == lst.size()) {
            lst.push_back(root->val);
        }
        
        if(root->right) {
            DFS(root->right, lst, level + 1);
        }
        
        if(root->left) {
            DFS(root->left, lst, level + 1);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}