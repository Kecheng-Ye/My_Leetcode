#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int tab = 0;
    
    void print_tab(int num) {
        for(int i = 0; i < num; i++) {
            printf("\t");
        }
    }
    // Time: O(nlogn), Space: O(n)
    // TreeNode* sortedListToBST(ListNode* head) {
    //     int size = 0;
    //     ListNode *temp = head;
    //     while(temp) {
    //         temp = temp->next;
    //         size++;
    //     }
        
    //     return traverse(head, 0, size - 1);
    // }
    
    // TreeNode* traverse(ListNode* head, int start, int end) {
    //     // print_tab(tab++);
    //     // printf("Now at linkedlist node %s, with start: %d, end: %d\n", (head ? to_string(head->val).c_str() : "null"), start, end);
        
        
    //     if(start > end) {
    //         // print_tab(--tab);
    //         // printf("Start bigger than end, return null\n");
    //         return nullptr;
    //     }
        
    //     if(start == end) {
    //         // print_tab(--tab);
    //         // printf("Start equal to end, return exactly this node %d\n", head->val);
    //         return new TreeNode(head->val);
    //     }
        
    //     int mid_step = (end - start) / 2;
    //     ListNode* mid = head;
        
    //     for(int i = 0; i < mid_step; i++) {
    //         mid = mid->next;
    //     }
        
    //     // print_tab(tab);
    //     // printf("mid step is %d, the result mid point is %d, the corresponding value is %d\n", mid_step, start + mid_step, mid->val);
        
    //     TreeNode *root = new TreeNode(mid->val);
    //     root->left = traverse(head, start, start + mid_step - 1);
    //     root->right = traverse(mid->next, start + mid_step + 1, end);
        
    //     // print_tab(--tab);
    //     // printf("Finish with start %d end %d and the node val is %d, and its left %s and right %s\n", start, end, mid->val, (root->left ? to_string(root->left->val).c_str() : "null"), (root->right ? to_string(root->right->val).c_str() : "null"));
    //     return root;
    // }
    
    ListNode *node;
    
    // Time: O(n), Space: O(n)
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        node = head;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            size++;
        }
        
        return inorder(0, size - 1);
    }
    
    TreeNode* inorder(int start, int end) {
        if(start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode *left = inorder(start, mid - 1);
        TreeNode *root = new TreeNode(node->val);
        node = node->next;
        TreeNode *right = inorder(mid + 1, end);
        root->left = left;
        root->right = right;
        
        return root;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}