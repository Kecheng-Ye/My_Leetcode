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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> dp;
        bool shouldEnd = false;

        const function<void(TreeNode*)> inorder = [&](TreeNode* curr) {
            if (!curr) return;

            inorder(curr->left);
            if (shouldEnd) return;

            dp.push_back(curr->val);
            if (dp.size() > k) {
                const double frontDiff = abs((double)dp.front() - target);
                const double backDiff = abs((double)dp.back() - target);

                if (frontDiff < backDiff) {
                    shouldEnd = true;
                    dp.pop_back();
                    return;
                } else {
                    dp.pop_front();
                }
            }

            inorder(curr->right);
        };

        inorder(root);
        return {dp.begin(), dp.end()};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}