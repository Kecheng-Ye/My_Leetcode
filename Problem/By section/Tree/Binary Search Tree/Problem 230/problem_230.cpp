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

// class Solution {
// public:
//     int count = 0;
//     int result;
    
//     // Time: O(n), Space: O(n)
//     int kthSmallest(TreeNode* root, int k) {
//         if(!root) return -1;
        
//         traverse(root, k);
//         return result;
//     }
    
//     bool traverse(TreeNode* root, int k) {
//         if(!root) return false;
        
//         if(traverse(root->left, k)) return true;
        
//         count++;
//         if(count == k) {
//             result = root->val;
//             return true;
//         }
        
//         return traverse(root->right, k);
//     }
// };

class Solution {
public:
    vector<int> nodes;

    int kthSmallest(TreeNode* root, int k) {
        nodes = vector<int>();
        morrisTraversal(root);
        return nodes[k - 1];
    }

    // Time: O(n), Space: O(1)
    void morrisTraversal(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                // reach out the left most point
                nodes.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *predecessor = findPredecessor(curr);

                if (!predecessor->right) {
                    // connect the predecessor to curr, so we dont need a stack to traverse back
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    // finish all the sub tree traversal on the left tree
                    // disconnect the artifical link we set it up and go to the right sub tree
                    assert(predecessor->right == curr);
                    predecessor->right = nullptr;
                    nodes.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

    TreeNode* findPredecessor(TreeNode* curr) {
        TreeNode *temp = curr->left;
        TreeNode *prev;

        while (temp && temp != curr) {
            prev = temp;
            temp = temp->right;
        }

        return prev; 
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}