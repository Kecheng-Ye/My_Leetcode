#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t1, t2;

        for (const int i : arr1) {
            t1.insert(to_string(i));
        }

        for (const int i : arr2) {
            t2.insert(to_string(i));
        }

        Trie::TreeNode *root1 = t1.root;
        Trie::TreeNode *root2 = t2.root;

        const function<int(Trie::TreeNode *, Trie::TreeNode *)> helper = [&](Trie::TreeNode *a, Trie::TreeNode *b) {
            if (!a || !b) return 0;

            int result = 0;
            for (int i = 0; i < 10; i++) {
                if (a->children[i] && b->children[i]) {
                    result = max(result, helper(a->children[i], b->children[i]));
                }
            }

            return result + 1;
        };

        return helper(root1, root2) - 1;
    }

private:
    class Trie {
    public:
        Trie(): root(new TreeNode()) {}

        void insert(const string& s) {
            TreeNode* temp = root;

            for (const char c : s) {
                if (!temp->children[c - '0']) {
                    temp->children[c - '0'] = new TreeNode();
                }

                temp = temp->children[c - '0'];
            }

            temp->isEnd = true;
        }

        class TreeNode {
        public:
            TreeNode(): children(10, nullptr), isEnd(false) {}

            ~TreeNode() {
                for (TreeNode* child : children) {
                    if (child) delete child;
                }
            }

            vector<TreeNode*> children;
            bool isEnd;
        };

        TreeNode* root;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}