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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> record;
        DFS(root, record, result);
        
        return result;
    }
    
    string DFS(TreeNode* root, unordered_map<string, int>& record, vector<TreeNode*>& result){
        if(!root) return "";
        
        string cur = to_string(root->val);
        string left_sub = DFS(root->left, record, result);
        string right_sub = DFS(root->right, record, result);
        
        string total = left_sub + ((left_sub != "") ? "l" : "") + 
                       cur + 
                       ((right_sub != "") ? "r" : "") + right_sub;
        
        if(record[total] == 1) {
            result.push_back(root);
        }
        
        record[total]++;
        
        return total;
    } 
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}