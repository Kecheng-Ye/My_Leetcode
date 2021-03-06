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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(left == 0 || right == 0) return left + right + 1;
        
        return min(left, right) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());
    cout << max << " " << min << endl;
    return 0;
}