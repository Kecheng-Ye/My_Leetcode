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
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return {};
        
        int depth = get_depth(root);
        int width = pow(2, depth) - 1;
        vector<vector<string>> result(depth, vector<string>(width));
        DFS(result, root, 0, width / 2, 1, depth);
        return result;
    }
    
    int get_depth(TreeNode* root) {
        if(!root) return 0;
        
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
    
    void DFS(vector<vector<string>>& result, TreeNode* root, int x, int y, int cur, int depth) {
        if(!root) return;
        
        result[x][y] = to_string(root->val);
        cur++;
        int stride = pow(2, depth - cur);
        
        // cout << y - stride << " " << y + stride;
        
        DFS(result, root->left, x + 1, y - stride, cur, depth);
        DFS(result, root->right, x + 1, y + stride, cur, depth);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}