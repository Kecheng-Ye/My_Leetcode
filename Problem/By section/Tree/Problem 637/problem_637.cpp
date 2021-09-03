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
    // Time: O(n), Space: O(m) (maximual number of nodes in one level)
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {0.0};
        
        vector<double> avg;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            double sum = 0.0;
            for(int i = 0; i< size; i++) {
                auto temp = q.front();
                sum += (double)temp->val;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            avg.push_back(((double)sum / size));
        }
        
        return avg;
        
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}