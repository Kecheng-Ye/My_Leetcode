#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

int tab = 0;
void print_indent(int num) {
    for(int i = 0; i < num; i++) {
        cout << "\t";
    }
}

class Solution {
public:
    // n: number of nodes
    // m: number of layers
    // Time: O(n), Space: O(m)
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        const auto& [_head, _tail] = helper(head);
        return _head;
    }

    pair<Node*, Node*> helper(Node* cur) {
        Node* temp = cur;
        Node* end;
        while (temp) {
            end = temp;
            if (temp->child) {
                Node* next = temp->next;

                const auto& [child_head, child_tail] = helper(temp->child);
                temp->child = nullptr;
                temp->next = child_head;
                child_head->prev = temp;
                end = child_tail;

                if (next) next->prev = child_tail;
                child_tail->next = next;

                temp = next;
            } else {
                temp = temp->next;
            }
        }

        return {cur, end};
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
