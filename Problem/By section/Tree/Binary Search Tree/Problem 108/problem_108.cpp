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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        
        if(start == end) return new TreeNode(nums[start]);
        
        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);
        
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}