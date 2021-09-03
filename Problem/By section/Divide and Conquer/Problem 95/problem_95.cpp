#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_tree(TreeNode* head) {
    if(head == nullptr) {
        return;
    }else{
        print_tree(head->left);
        cout << head->val << " ";
        print_tree(head->right);
    }
}

class Solution {
private:
    vector<vector<TreeNode*>> records;

public:
    // vector<TreeNode*> generateTrees(int n) {
    //     records = vector<vector<TreeNode*>>(n * n, vector<TreeNode*>{});
    //     return generateTrees_helper(1, n, n);
    // }

    // vector<TreeNode*> generateTrees_helper(int left, int right, int n) {
    //     if(left > right) {
    //         return vector<TreeNode*>{nullptr};
    //     }else if(left == right) {
    //         TreeNode *head = new TreeNode(left);
    //         return vector<TreeNode*>{head};
    //     }else if(records[(left - 1) * n + (right - 1)].size() != 0) {
    //         return records[(left - 1) * n + (right - 1)];
    //     }else{
    //         vector<TreeNode*> result;

    //         for(int i = left; i <= right; i++) {
    //             vector<TreeNode*> left_tree = generateTrees_helper(left, i - 1, n);
    //             vector<TreeNode*> right_tree = generateTrees_helper(i + 1, right, n);

    //             for(auto l : left_tree) {
    //                 for(auto r : right_tree) {
    //                     TreeNode *head = new TreeNode(i);
    //                     head->left = l;
    //                     head->right = r;
    //                     result.push_back(head);
    //                 }
    //             }
    //         }

    //         records[(left - 1) * n + (right - 1)] = result;
    //         return result;
    //     }
        
    // }

    map<pair<int, int>, vector<TreeNode*>> map;

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees_helper(1, n, n);
    }

    vector<TreeNode*> generateTrees_helper(int left, int right, int n) {
        if(left > right) {
            return vector<TreeNode*>{nullptr};
        }else if(left == right) {
            TreeNode *head = new TreeNode(left);
            return vector<TreeNode*>{head};
        }else if(map.count(make_pair(left, right))) {
            return map[make_pair(left, right)];
        }else{
            vector<TreeNode*> result;

            for(int i = left; i <= right; i++) {
                vector<TreeNode*> left_tree = generateTrees_helper(left, i - 1, n);
                vector<TreeNode*> right_tree = generateTrees_helper(i + 1, right, n);

                for(auto l : left_tree) {
                    for(auto r : right_tree) {
                        TreeNode *head = new TreeNode(i);
                        head->left = l;
                        head->right = r;
                        result.push_back(head);
                    }
                }
            }

            map[make_pair(left, right)] = result;
            return result;
        }
        
    }
};


int main(int argc, char** argv) {
    Solution s;
    auto result = s.generateTrees(3);

    // auto result = s.generateTrees_helper(3,3);
    // print_tree(result[0]);
    for(auto tree : result) {
        print_tree(tree);
        cout << endl;
    }

    // for(auto tree : result) {
    //     print_tree(tree);
    //     cout << endl;
    // }

    // TreeNode head(1);
    // TreeNode left(0);
    // TreeNode right(2);

    // head.left = &left;
    // head.right = &right;

    // print_tree(&head);

    return 0;
}