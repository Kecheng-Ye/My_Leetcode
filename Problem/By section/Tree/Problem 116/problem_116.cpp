#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // Time: O(n), Space: O(1)
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* left_most = root;
        
        while(left_most) {
            Node *temp = left_most;
            
            // traverse all the node in one level
            while(temp) {
                if(temp->left) {
                    // connect two children
                    temp->left->next = temp->right;
                    
                    // connect two nearby children with different parent
                    if(temp->next) {
                        temp->right->next = temp->next->left;
                    }
                }
                
                temp = temp->next;
            }
            
            // go to next level
            left_most = left_most->left;
        }
        
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}