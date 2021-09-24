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
    // Time: O(n), Space: O(n)
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int _max = INT_MIN;
            
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                _max = max(_max, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            result.push_back(_max);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}