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
    int getMinimumDifference(TreeNode* root) { 
        if(!root) return INT_MAX;
        
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        int result = INT_MAX;
        
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            if(prev) result = min(result, curr->val - prev->val);
            prev = curr;
            curr = curr->right;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}