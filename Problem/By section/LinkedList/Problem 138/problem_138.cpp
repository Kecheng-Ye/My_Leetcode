#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> record;
    
    // Time: O(n), Space: O(n)
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node *temp = head;
        record = unordered_map<Node*, Node*>();
        Node *new_node = new Node(head->val);
        record[head] = new_node;
        
        while(new_node) {
            new_node->next = generateNode(temp->next);
            new_node->random = generateNode(temp->random);
            
            temp = temp->next;
            new_node = new_node->next;
        }
        
        return record[head];
    }
    
    Node* generateNode(Node* head) {
        if(!head) return head;
        
        if(!record.count(head)) {
            record[head] = new Node(head->val);   
        }
        
        return record[head];
    }
    
//     unordered_map<Node*, Node*> record;
       // Time: O(n), Space: O(n)
//     Node* copyRandomList(Node* head) {
//         record = unordered_map<Node*, Node*>();
//         return DFS(head);
//     }
    
//     Node* DFS(Node* head) {
//         if(!head) return nullptr;
        
//         if(record.count(head)) {
//             return record[head];
//         }
        
//         Node* result = new Node(head->val);
//         record[head] = result;
        
//         result->next = DFS(head->next);
//         result->random = DFS(head->random);
        
//         return result;
//     }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}