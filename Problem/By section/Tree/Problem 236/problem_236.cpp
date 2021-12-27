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
    TreeNode *ans;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        traverse(root, p, q);
        return ans;
    }
    
    // traverse(root) will only return {1, 0}, denoting if the subtree start at root can meet target node p or q
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        
        int meet_target_node_left = traverse(root->left, p, q);
        int meet_target_node_right = traverse(root->right, p, q);
        int meet_target_node_self = (root == p || root == q);
        
        // if we reach both of the target node
        // we know it is a LCA
        if(meet_target_node_left + meet_target_node_right + meet_target_node_self >= 2) {
            ans = root;
        }
        
        // Note !!!
        // we only return if one target node has been detected from this root
        // in this case, the above if statement will only be satisfied by once, which is indeed a LCA
        return (meet_target_node_left + meet_target_node_right + meet_target_node_self > 0);
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}