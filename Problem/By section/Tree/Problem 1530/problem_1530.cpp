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
    // n = num of leaves
    // Time: O(n^2), Space: O(h)
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        
        const function<unordered_map<int, int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return unordered_map<int, int>{};

            if (!root->left && !root->right) return unordered_map<int, int>{{0, 1}};

            unordered_map<int, int> left = dfs(root->left);
            unordered_map<int, int> right = dfs(root->right);

            unordered_map<int, int> output;

            for (const auto& [depthL, freqL] : left) {
                for (const auto& [depthR, freqR] : right) {
                    if ((depthL + 1 + depthR + 1) <= distance) {
                        result += (freqL * freqR);
                    }
                }
                output[depthL + 1] += freqL;
            }
            
            for (const auto& [depthR, freqR] : right) {
                output[depthR + 1] += freqR;
            }

            return output;
        };

        dfs(root);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}