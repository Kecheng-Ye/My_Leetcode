#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    // Time: O(m + n), Space: O(1)
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(p == q) return p;
        
        Node *cur_p = p, *cur_q = q;
        
        while(cur_p != cur_q) {
            cur_p = (cur_p->parent) ? cur_p->parent : q;
            cur_q = (cur_q->parent) ? cur_q->parent : p;
        }
        
        return cur_p;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}