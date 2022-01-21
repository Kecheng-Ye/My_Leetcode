#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // Time: O(n), Space: O(n)
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        
        auto [head, tail] = helper(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
    
    pair<Node*, Node*> helper(Node* root) {
        if(!root->left && !root->right) {
            return {root, root};
        }
        
        auto [left_head, left_tail] = (root->left) ? helper(root->left) : make_pair(root, root);
        auto [right_head, right_tail] = (root->right) ? helper(root->right) : make_pair(root, root);
        
        if(left_tail != root) {
            left_tail->right = root;
            root->left = left_tail;   
        }
        
        if(right_tail != root) {
            right_head->left = root;
            root->right = right_head;
        }
        
        return {left_head, right_tail};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}