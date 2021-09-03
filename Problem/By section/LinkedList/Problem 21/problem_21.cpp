#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative Approach
    // Time: O(n), Space: O(1)
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     ListNode *i = l1, *j = l2;
    //     ListNode result(INT_MIN);
    //     ListNode *temp = &result;
    //     while(i != nullptr || j != nullptr) {
    //         if(i == nullptr) {
    //             temp->next = j;
    //             break;
    //         }else if(j == nullptr) {
    //             temp->next = i;
    //             break;
    //         }else{
    //             if(i->val <= j->val) {
    //                 temp->next = i;
    //                 i = i->next;
    //             }else{
    //                 temp->next = j;
    //                 j = j->next;
    //             }
    //         }
            
    //         temp = temp->next;
    //     }
        
    //     return result.next;
    // }

    // Recursive Approach
    // Time: O(n), Space: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}