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

// class Solution {
// public:
//     // Two Pass
//     // Time: O(n), Space: O(n)
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         if (!root) return {};

//         minIdx = 0; maxIdx = 0;
//         getTreeSpan(root, 0);

//         vector<vector<int>> result(maxIdx - minIdx + 1);
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});

//         while (!q.empty()) {
//             int currLvl = q.size();

//             while (currLvl--) {
//                 const auto [node, idx] = q.front(); q.pop();

//                 result[idx - minIdx].push_back(node->val);

//                 if (node->left) q.push({node->left, idx - 1});
//                 if (node->right) q.push({node->right, idx + 1});
//             }
//         }

//         return result;
//     }

// private:
//     void getTreeSpan(TreeNode* root, int currIdx) {
//         if (!root) return;

//         minIdx = min(minIdx, currIdx);
//         maxIdx = max(maxIdx, currIdx);

//         getTreeSpan(root->left, currIdx - 1);
//         getTreeSpan(root->right, currIdx + 1);
//     }

//     int minIdx;
//     int maxIdx;
// };

class Solution {
public:
    // One pass
    // Time: O(n), Space: O(n)
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        int minIdx = 0, maxIdx = 0;

        unordered_map<int, vector<int>> record;
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int currLvl = q.size();

            while (currLvl--) {
                const auto [node, idx] = q.front(); q.pop();
                minIdx = min(minIdx, idx);
                maxIdx = max(maxIdx, idx);

                record[idx].push_back(node->val);

                if (node->left) q.push({node->left, idx - 1});
                if (node->right) q.push({node->right, idx + 1});
            }
        }

        for (int i = minIdx; i <= maxIdx; i++) {
            result.push_back(record[i]);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}