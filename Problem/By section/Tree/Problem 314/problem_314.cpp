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
    int _min = INT_MAX;
    int _max = INT_MIN;
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        
        unordered_map<TreeNode*, int> record;
        DFS(record, root, 0);
        
        vector<vector<int>> result(_max - _min + 1);
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            result[record[top] - _min].push_back(top->val);
            
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        
        
        return result;
    }
    
    void DFS(unordered_map<TreeNode*, int>& result, TreeNode* root, int index) {
        if(!root) return;
        
        result[root] = index;
        _min = min(index, _min);
        _max = max(index, _max);
        
        DFS(result, root->left, index-1);
        DFS(result, root->right, index + 1);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}