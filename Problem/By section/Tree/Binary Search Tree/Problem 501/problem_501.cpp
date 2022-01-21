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
    int cur_freq = 1;
    int max_freq = 1;
    TreeNode* prev_node = nullptr;
    
    // Time: O(n), Space: O(n)
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode* root, vector<int>& result) {
        if(!root) return;
        
        inorder(root->left, result);
        if(prev_node) {
            if(prev_node->val == root->val) {
                cur_freq++;
                if(cur_freq > max_freq) {
                    max_freq = cur_freq;
                    result.clear();
                    result.push_back(root->val);
                }else if(cur_freq == max_freq ) {
                    result.push_back(root->val); 
                }
            }else{
                cur_freq = 1;
            }
        }
            
        prev_node = root;
        if(max_freq == 1) result.push_back(root->val);
        inorder(root->right, result);
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}