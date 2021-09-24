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
    void recoverTree(TreeNode* root) {
        if(!root) return;
        
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        stack<TreeNode*> s;
        TreeNode *first_abnormal, *second_abnormal;
        bool find_one = false;
        
        while(cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode *temp = s.top();
            s.pop();
            
            if(prev) {
                if(prev->val > temp->val) {
                    if(!find_one) {
                        first_abnormal = prev;
                        find_one = true;
                    }
                    second_abnormal = temp;
                }
            }
            
            prev = temp;
            cur = temp->right;
        }
        
        int temp = first_abnormal->val;
        first_abnormal->val = second_abnormal->val;
        second_abnormal->val = temp; 
        
        return;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}