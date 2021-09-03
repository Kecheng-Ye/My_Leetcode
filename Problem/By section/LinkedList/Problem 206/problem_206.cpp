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
//     Iterative Approach
//     Time: O(n), Space: O(1)
//     ListNode* reverseList(ListNode* head) {
//         ListNode *prev = NULL, *cur = head, *next = head;
        
//         while(cur != NULL) {
//             next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
        
//         return prev;
//     }

    // Recursive Approach
    // Time: O(n), Space: O(1)
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* after_part = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return after_part;
    }
};

void foo(int* a) {
    a = NULL;
}

int main(int argc, char** argv) {
    Solution s;

    int a = 5;
    int *b = &a;
    foo(b);
    cout << b;

    return 0;
}