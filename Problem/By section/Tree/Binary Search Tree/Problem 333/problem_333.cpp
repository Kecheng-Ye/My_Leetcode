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
    int result;
    
    // Time: O(n), Space: O(n)
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        
        if(!(root->left) && !(root->right)) return 1;
        
        result = 0;
        
        helper(root);
        
        return result;
    }
    
private:
    struct answer {
        int _min;
        int _max;
        int size;
        
        answer(int _min, int _max, int size) : _min(_min), _max(_max), size(size) {};
    };    

    answer helper(TreeNode* root) {
        // 0 means invalid, -1 means nullptr
        if(!root) return {-1, -1, -1};
        
        answer cur_res = {root->val, root->val, 1};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if(left.size >= 0) {
            // if left tree do exist a valid BST 
            // and root node's val is bigger than left tree' max
            if(left.size > 0 && root->val > left._max) {
                cur_res._min = left._min;
                cur_res.size += left.size;
            }else{
                cur_res.size = 0;
            }
        }
        
        if(cur_res.size && right.size >= 0) {
            if(right.size > 0 && root->val < right._min) {
                cur_res.size += right.size;
                cur_res._max = right._max;
            }else{
                cur_res.size = 0;
            }
        }
        
        result = max(result, cur_res.size);
        
        return cur_res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}