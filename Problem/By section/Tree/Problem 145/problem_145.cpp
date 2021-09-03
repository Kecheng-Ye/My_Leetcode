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
    //Time: O(n), Space: O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        stack<TreeNode*> s;
        vector<int> result;
        s.push(root);
        
        while(!s.empty()) {
            auto node = s.top();
            s.pop();
            
            // postorder = left->right->root
            // reverse it, then it becomes
            // root->right->left
            result.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}