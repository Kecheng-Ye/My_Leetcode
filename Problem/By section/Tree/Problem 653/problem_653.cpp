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
    // Inorder with hashset
    // Time: O(n), Space: O(n)
    // bool findTarget(TreeNode* root, int k) {
    //     if(!root) return false;
        
    //     unordered_set<int> record;
    //     stack<TreeNode*> s;
    //     TreeNode* temp = root;
        
    //     while(temp || !s.empty()) {
    //         while(temp) {
    //             s.push(temp);
    //             temp = temp->left;
    //         }
            
    //         temp = s.top();
    //         s.pop();
            
    //         if(record.count(k - temp->val)) return true;
    //         record.insert(temp->val);
    //         temp = temp->right;
            
    //     }
        
        
    //     return false;
    // }
    
    // Inorder with two ptr
    // Time: O(n), Space: O(n)
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> small_ptr;
        stack<TreeNode*> big_ptr;
        
        TreeNode* small = root;
        TreeNode* big = root;
        
        while(small) {
            small_ptr.push(small);
            small = small->left;
        }
        
        while(big) {
            big_ptr.push(big);
            big = big->right;
        }
        
        while(small_ptr.top() != big_ptr.top()) {
            TreeNode *l = small_ptr.top(), *r = big_ptr.top();
            
            if(l->val + r->val == k) {
                return true;
            }else if(l->val + r->val < k){
                small_ptr.pop();
                if(l->right) {
                    l = l->right;
                    while(l) {
                        small_ptr.push(l);
                        l = l->left;
                    }
                }
            }else{
                big_ptr.pop();
                if(r->left) {
                    r = r->left;
                    while(r) {
                        big_ptr.push(r);
                        r = r->right;
                    }
                }
            }
            
        }
        
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}