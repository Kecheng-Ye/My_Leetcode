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

int tab = 0;

void print_indet(int num) {
    for(int i = 0; i < num; i++) {
        printf("\t");
    }
}

class Solution {
public:
    int result = -1;
    
    // Time: O(n), Space: O(n)
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        
        traverse(root, root->val);
        
        return result;
    }
    
    void traverse(TreeNode* root, int root_val) {
        print_indet(tab++);
        printf("Traverse at node %d\n", (root) ? root->val : -1);
        
        if(!root) {
            print_indet(--tab);
            printf("This node is null so we trivially return\n");
            return;
        }
        
        if(root->val != root_val) {
            if(result == -1) {
                print_indet(tab);
                printf("No previous result detected, so we set the result to %d\n", root->val);
                result = root->val;
            }else{
                print_indet(tab);
                printf("Meet a new potential answer, the original result is %d, and the new candidate is %d\n", result, root->val);
                result = min(result, root->val);
            }
        }else{
            traverse(root->left, root_val);
            traverse(root->right, root_val);
        }
        --tab;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    TreeNode a(2);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(5);
    TreeNode e(7);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    e.right = &e;

    s.findSecondMinimumValue(&a);

    return 0;
}