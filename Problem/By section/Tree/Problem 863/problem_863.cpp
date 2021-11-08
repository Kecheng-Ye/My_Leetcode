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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return {};
        
        unordered_map<TreeNode*, TreeNode*> parents;
        Find_parents(root, parents);
        
        queue<TreeNode*> q;
        vector<int> result;
        unordered_set<TreeNode*> is_visited;
        q.push(target);
        is_visited.insert(target);
        
        while(!q.empty() || k > 0) {
            int size = q.size();
            
            while(size--) {
                auto temp = q.front();
                q.pop();
                if(!k) result.push_back(temp->val);
                
                if(temp->left && !is_visited.count(temp->left)) {
                    q.push(temp->left);
                    is_visited.insert(temp->left);
                }
                
                if(temp->right && !is_visited.count(temp->right)) {
                    q.push(temp->right);
                    is_visited.insert(temp->right);
                }
                
                if(parents[temp] && !is_visited.count(parents[temp])) {
                    q.push(parents[temp]);
                    is_visited.insert(parents[temp]);
                }
            }
            
            k--;
        }
        
        return result;
    }
    
    void Find_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> q;
        q.push(root);
        parents[root] = nullptr;
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            if(temp->left) {
                parents[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right) {
                parents[temp->right] = temp;
                q.push(temp->right);
            }
        }

    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}