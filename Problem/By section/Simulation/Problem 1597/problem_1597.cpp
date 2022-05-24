#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Node* expTree(string s) {
        // we use vector as a stack to parse s
        // since to ensure the computation sequence, we will construct the tree from the front of the "stack" in the end, thus, we can't use stack
        // if we meet '(', we will parse the content inside of the parentheses first
        // if we meet '*' or '/', we create a node and set the back of the vector as its left child, and replace the back with the new node
        // if we meet '+' or '-', we will just push it to the back of the vector
        // if we meet digit, if the vector is empty or the back of the vector is '+' or '-', we push it to the back of the vector
        // otherwise, we set the digit as the right child of the back of the vector
        int index = 0;
        return constructTree(s, index);
    }
    
    Node* constructTree(string& s, int& index) {
        vector<Node*> nodeVec;
        while (index < s.size()) {
            if (s[index] == ')') {
                index++;
                break;
            }
            
            if (s[index] == '*' || s[index] == '/') {
                Node* n = new Node(s[index]);
                n->left = nodeVec.back();
                *prev(nodeVec.end()) = n;
                index++;
            } else if (s[index] == '+' || s[index] == '-') {
                nodeVec.push_back(new Node(s[index]));
                index++;
            } else {
                Node* n = NULL;
                if (s[index] == '(') {
                    index++;
                    n = constructTree(s, index);
                } else {
                    n = new Node(s[index]);
                    index++;
                }
                if (nodeVec.size() == 0) {
                    nodeVec.push_back(n);
                } else {
                    Node* topNode = nodeVec.back();
                    if (topNode->val == '*' || topNode->val == '/') {
                        topNode->right = n;
                    } else {
                        nodeVec.push_back(n);
                    }
                }
            }
        }
         
        Node* root = NULL;
        for (auto& n : nodeVec) {
            if (root == NULL) {
                root = n;
            } else {
                if (n->val == '+' || n->val == '-') {
                    n->left = root;
                    root = n;
                } else {
                    root->right = n;
                }
            }
        }
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}