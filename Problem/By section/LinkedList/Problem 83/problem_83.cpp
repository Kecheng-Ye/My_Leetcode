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
    // Recursive Approach
    // Time: O(n), Space: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicates(head, -101);
    }
    
    ListNode* deleteDuplicates(ListNode* head, int prev) {
        if(!head) {
            return head;
        }else if(head->val == prev) {
            return deleteDuplicates(head->next, prev);
        }else{
            head->next = deleteDuplicates(head->next, head->val);
            return head;
        }
        
    }

    // Iterative Approach
    // Time: O(n), Space: O(1)
    // ListNode* deleteDuplicates(ListNode* head) {
    //     ListNode* current = head;
    //     while (current != nullptr && current->next != nullptr) {
    //         if (current->next->val == current->val) {
    //             current->next = current->next->next;
    //         } else {
    //             current = current->next;
    //         }
    //     }
    //     return head;
    // }
};


int main(int argc, char** argv) {
    Solution s;
    
    int a, b;
    b = a;
    a = 1;
    cout << b << endl;

    return 0;
}