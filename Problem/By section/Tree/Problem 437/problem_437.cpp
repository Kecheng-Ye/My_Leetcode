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
    // Time: O(NlogN), Space: O(NlogN)
    // int pathSum(TreeNode* root, int targetSum) {
    //     if(!root) return 0;
    //     int result = pathSum_Root(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
            
    //     return result;
    // }
    
    // int pathSum_Root(TreeNode* root, int targetSum) {
    //     if(!root) return 0;
    //     int result = 0;
    //     if(targetSum == root->val) result += 1;
        
    //     result += pathSum_Root(root->left, targetSum - root->val) + pathSum_Root(root->right, targetSum - root->val);
        
    //     return result;
    // }
    
    // Time: O(N), Space: O(N)
    int result = 0;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefix_record;
        traverse(root, targetSum, 0, prefix_record);
        
        return result;
    }
    
    void traverse(TreeNode* root, int targetSum, int curr_Sum, unordered_map<int, int>& prefix_record) {
        if(!root) return;
        
        curr_Sum += root->val;
        
        if(curr_Sum == targetSum) {
            result++;
        }
        
        result += prefix_record[curr_Sum - targetSum];
        
        prefix_record[curr_Sum] += 1;
        
        traverse(root->left, targetSum, curr_Sum, prefix_record);
        traverse(root->right, targetSum, curr_Sum, prefix_record);
        
        prefix_record[curr_Sum] -= 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}