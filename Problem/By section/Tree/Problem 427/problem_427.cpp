#include <bits/stdc++.h>

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        const int m = grid.size();
        return constructSingleNode(grid, 0, 0, m);
    }

private:
    Node* constructSingleNode(const vector<vector<int>>& grid, const int x, const int y, int n) {
        if (n == 1) {
            return new Node(
                grid[x][y],
                true
            );
        }

        Node *currentNode = new Node(
            grid[x][y],
            false
        );

        const int mid = n / 2;
        Node *leftTop = constructSingleNode(
            grid, x, y, mid
        );

        Node *rightTop = constructSingleNode(
            grid, x, y + mid, mid
        );

        Node *leftBot = constructSingleNode(
            grid, x + mid, y, mid
        );

        Node *rightBot = constructSingleNode(
            grid, x + mid, y + mid, mid
        );

        if (canMerge(leftTop, rightTop, leftBot, rightBot)) {
            currentNode->val = leftTop->val;
            currentNode->isLeaf = true;
            delete leftTop;
            delete rightTop;
            delete leftBot;
            delete rightBot;
        } else {
            currentNode->topLeft = leftTop;
            currentNode->topRight = rightTop;
            currentNode->bottomLeft = leftBot;
            currentNode->bottomRight = rightBot;
        }

        return currentNode;
    }

    bool canMerge(Node *leftTop, Node *rightTop, Node *leftBot, Node *rightBot) {
        return (
            leftTop->isLeaf &&
            rightTop->isLeaf &&
            leftBot->isLeaf &&
            rightBot->isLeaf &&
            leftTop->val == rightTop->val &&
            leftTop->val == leftBot->val &&
            leftTop->val == rightBot->val
        );
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}