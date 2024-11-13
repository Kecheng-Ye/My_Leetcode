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
    TreeNode* result;

    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        const auto& [smaller, bigger] = breakTargetNode(root, target);

        return {smaller, bigger};
    }

    pair<TreeNode*, TreeNode*> breakTargetNode(TreeNode* curr, const int target) {
        if (!curr) return {nullptr, nullptr};

        if (curr->val > target) {
            const auto& [smaller, bigger] = breakTargetNode(curr->left, target);
            curr->left = bigger;
            return {smaller, curr};
        } else {
            TreeNode* smaller = curr;
            const auto& [rightSmaller, bigger] = breakTargetNode(curr->right, target);
            smaller->right = rightSmaller;
            return {smaller, bigger};
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}