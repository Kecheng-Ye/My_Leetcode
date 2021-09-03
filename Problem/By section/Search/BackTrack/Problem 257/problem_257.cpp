#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == nullptr) {
            
        }else if(root->left == nullptr && root->right == nullptr) {
            result.push_back(to_string(root->val));
        }else{
            string single_result = "";

            backtrack(root, result, single_result);

        }
        
        return result;   
    }

    void backtrack(TreeNode* current, vector<string>& result, string& single_result) {
        if(current == nullptr) {
            return;
        }else if(current->left == nullptr && current->right == nullptr) {
            string temp(single_result.begin() + 2, single_result.end());
            temp += "->" + to_string(current->val);
            result.push_back(temp);
        }else{
            int size = single_result.length();

            single_result += "->" + to_string(current->val);

            backtrack(current->left, result, single_result);
            backtrack(current->right, result, single_result);

            single_result.erase(single_result.begin() + size, single_result.end());
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}