#include <bits/stdc++.h>

using namespace std;

#define null_str "null"

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        return to_string(root->val) + "{" +  serialize(root->left) + "}" + "[" + serialize(root->right) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        cout << data << endl;
        return deserializeHelper(data, idx);
    }

private:
    TreeNode* deserializeHelper(const string& data, int& idx) {
        if (!isdigit(data[idx]) && data[idx] != '-') {
            return nullptr;
        } 

        const int sign = data[idx] == '-' ? -1 : 1;
        if (sign == -1) idx++;
        const int value = readNum(data, idx);
        TreeNode* result = new TreeNode(sign * value);

        assert(data[idx] == '{');
        idx++;
        result->left = deserializeHelper(data, idx);
        assert(data[idx] == '}');
        idx++;

        assert(data[idx] == '[');
        idx++;
        result->right = deserializeHelper(data, idx);
        assert(data[idx] == ']');
        idx++;

        return result;
    }

    int readNum(const string& data, int& idx) {
        int result = 0;

        while (isdigit(data[idx])) {
            result = result * 10 + (data[idx] - '0');
            idx++;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}