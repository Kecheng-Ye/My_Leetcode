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
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        
        result = 0;
        DFS(root);
        return result;
    }
    
    pair<int, int> DFS(TreeNode* cur) {
        if(!cur) return {-1, -1};
        
        const auto [l_l, l_r] = DFS(cur->left);
        const auto [r_l, r_r] = DFS(cur->right);
        result = max(result, 1 + max(l_r, r_l));
        return {1 + l_r, 1 + r_l};
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}