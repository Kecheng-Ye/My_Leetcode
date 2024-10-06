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
    int closestValue(TreeNode* root, double target) {
        prev = INT_MIN;
        result = root->val;

        inorderTraverse(root, target);
        return result;
    }

private:
    bool inorderTraverse(TreeNode* root, const double target) {
        if (!root) return false;

        if(inorderTraverse(root->left, target)) return true;;

        result = root->val;
        const double prevDiff = (double)(prev) - target;
        const double currDiff = (double)(root->val) - target;

        if (prev <= target && target < root->val) {
            result = abs(prevDiff) <= abs(currDiff) ? prev : root->val;
            return true;
        }

        prev = root->val;
        return inorderTraverse(root->right, target);
    }

    int prev;
    int result;
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}