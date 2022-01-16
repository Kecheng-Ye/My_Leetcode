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
        if(!root) return null_str;
        
        return to_string(root->val) + "[" + serialize(root->left) + "," + serialize(root->right) + "]";
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
        
        return helper(data);
    }
    
    TreeNode* helper(string& data) {
        int num = 0;
        TreeNode* cur;
        if(!get_num(data, num)) {
            cur = nullptr;
        }else{
            cur = new TreeNode(num);   
        }
        
        if(data[idx] == '[') {
            idx++;
            cur->left = helper(data);
            cur->right = helper(data);
        }
        
        if(data[idx] == ']' || data[idx] == ',') {
            idx++;
        }
        
        return cur;
    }
    
    bool get_num(string& data, int& result) {
        if(isalpha(data[idx])) {
            assert(data.substr(idx, 4) == null_str);
            idx += 4;
            return false;
        }else{
            int sign = 1;
            if(data[idx] == '-') {
                sign = -1;
                idx++;
            }
            
            int num = 0;
            while(isdigit(data[idx])) {
                num = num * 10 + (data[idx++] - '0');
            }
            
            result = sign * num;
            return true;
        }
    }
    
private:
    int idx;
};

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}