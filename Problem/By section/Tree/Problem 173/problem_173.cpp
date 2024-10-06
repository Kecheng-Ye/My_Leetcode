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

class BSTIterator {
public:
    BSTIterator(TreeNode* root): st() {
        TreeNode* temp = root;
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* curr = st.top(); st.pop();

        int result = curr->val;

        curr = curr->right;
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        return result;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }

private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char** argv) {
    
    return 0;
}