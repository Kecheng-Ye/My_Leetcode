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
    // Time: O(n) Space: O(h)
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;

        const function<int(TreeNode*)> helper = [&](TreeNode* root) {
            if (!root) return 0;

            const int leftDepth = helper(root->left);
            const int rightDepth = helper(root->right);

            const int currDepth = 1 + max(leftDepth, rightDepth);

            if (currDepth > result.size()) {
                assert(currDepth == result.size() + 1);
                result.push_back({root->val});
            } else {
                result[currDepth - 1].push_back(root->val);
            }

            return currDepth;
        };

        helper(root);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}