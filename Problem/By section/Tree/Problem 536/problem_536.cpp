#include <bits/stdc++.h>

using namespace std;

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

class Solution {
public:
    // Time: O(n), Space: O(logn)
    TreeNode* str2tree(string s) {
        int index = 0;
        
        return str2tree_helper(s, index);
    }
    
    TreeNode* str2tree_helper(string& s, int& index) {
        if(index >= s.size()) return nullptr;
        
        int sign = 1;
        if(s[index] == '-') {
            index++;
            sign = -1;
        }
        
        int num = 0;
        while(index < s.size() && isdigit(s[index])) {
            num = num * 10 + (s[index++] - '0');
        }
        
        TreeNode* cur = new TreeNode(sign * num);
        
        if(s[index] == ')') {
            index++;
        }else if(s[index] == '(') {
            index++;
            cur->left = str2tree_helper(s, index);
            if(s[index] == '(') {
                index++;
                cur->right = str2tree_helper(s, index);
            }
            index++;
        }
        
        return cur;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}