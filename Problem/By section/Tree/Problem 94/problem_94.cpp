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
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root) return vector<int>();
        
//         vector<int> result;
//         stack<TreeNode*> s;
//         s.push(root);
//         unordered_set<TreeNode*> record;
        
        
//         while(!s.empty()) {
//             auto temp = s.top();
            
//             if(!temp->left) { // reach left most leaf
//                 result.push_back(temp->val);
//                 s.pop();
//                 if(temp->right) s.push(temp->right); // don't forget to add right subtree
//             }else if(record.count(temp)) { // if you already seen this node, meaning all left subtree has been discovered
//                 result.push_back(temp->val);
//                 s.pop();
//             }else{
//                 record.insert(temp);
//                 s.pop(); // pop first, then you should add by the sequence: right -> root -> left
//                 if(temp->right) s.push(temp->right);
//                 s.push(temp);
//                 if(temp->left) s.push(temp->left);
//             }
//         }
        
//         return result;
//     }
    
    // no need for record
    // Time: O(n), Space: O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        
        vector<int> result;
        stack<TreeNode*> s;
        // initialize a ptr for current left most ptr
        TreeNode* ptr = root;
        
        while(ptr || !s.empty()) {
            while(ptr) {
                s.push(ptr);
                ptr = ptr->left;
            }
            
            auto temp = s.top();
            s.pop();
            result.push_back(temp->val);
            
            ptr = temp->right;
            
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}