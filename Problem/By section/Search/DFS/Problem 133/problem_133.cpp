#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // Time: O(n), Space: O(n)
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        vector<Node*> records(100 + 1, nullptr);

        Node* result = explore(node, records);
        return result;
    }

    Node* explore(const Node* cur, vector<Node*>& records) {
        if (!records[cur->val]){
            Node* cloneNode = new Node(cur->val);

            records[cur->val] = cloneNode;

            for (const Node* neighbour : cur->neighbors) {
                (cloneNode->neighbors).push_back(explore(neighbour, records));
            }
        }

        return records[cur->val];
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
