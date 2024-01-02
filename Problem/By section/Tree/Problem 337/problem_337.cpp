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
    // map<TreeNode*, int> record;

    // Time: O(n), Space: O(n)
    // int rob(TreeNode* root) {
    //     if(!root) return 0;

    //     if(record.count(root)) return record[root];

    //     int ans = max(traverse(root), rob(root->left) + rob(root->right));
    //     record[root] = ans;

    //     return ans;
    // }

    // int traverse(TreeNode* root) {
    //     if(!root) return 0;

    //     int ans = root->val;

    //     if(root->left) {
    //         ans += rob(root->left->left) + rob(root->left->right);
    //     }

    //     if(root->right) {
    //         ans += rob(root->right->left) + rob(root->right->right);
    //     }

    //     return ans;
    // }

    // DP approach
    // dp_rob_i = dp_not_rob[left_child_i] + dp_not_rob[right_child_i]
    // dp_not_rob_i = max(dp_not_rob[left_child_i], dp_rob_i[left_child_i]) + max(dp_not_rob[right_child_i], dp_rob_i[right_child_i])
    // Time: O(n), Space: O(n)
    int rob(TreeNode* root) {
        if(!root) return 0;

        vector<TreeNode*> tree_arr;
        // q store one TreeNode and its corresponding parent index that stored in the tree_arr
        queue<pair<TreeNode*, int>>  q;
        // childs[i] = all the direct child from tree_arr[i]
        vector<vector<int>> childs;

        int index = -1;
        q.push({root, index});

        while(!q.empty()) {
            auto ele = q.front();
            q.pop();
            index++;

            TreeNode *temp = ele.first;
            int parent_idx = ele.second;

            // add new element to both tree_arr and childs
            tree_arr.push_back(temp);
            childs.push_back({});

            // update the childs for parent node
            if(parent_idx >= 0) {
                childs[parent_idx].push_back(index);
            }

            if(temp->left)  q.push({temp->left, index});
            if(temp->right) q.push({temp->right, index});

        }

        int n = index + 1;

        vector<int> dp_rob(n, 0);
        vector<int> dp_not_rob(n, 0);

        for(int i = n - 1; i >= 0; i--){
            auto child = childs[i];

            if(!child.size()) {
                dp_rob[i] = tree_arr[i]->val;
                dp_not_rob[i] = 0;
            }else{
                dp_rob[i] = tree_arr[i]->val;
                dp_not_rob[i] = 0;
                for(auto& each_child : child) {
                    dp_rob[i] += dp_not_rob[each_child];
                    dp_not_rob[i] += max(dp_rob[each_child], dp_not_rob[each_child]);
                }
            }

        }

        return max(dp_rob[0], dp_not_rob[0]);
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
