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
    // Time: O(n) Space: O(n)
    // ListNode* removeNodes(ListNode* head) {
    //     stack<ListNode*> st;
    //     removeNodes(head, st);

    //     ListNode *curr, *prev = nullptr;
    //     while (!st.empty()) {
    //         curr = st.top();
    //         st.pop();
    //         curr->next = prev;
    //         prev = curr;
    //     }

    //     return curr;
    // }
    
    // void removeNodes(ListNode* head, stack<ListNode*>& st) {
    //     if (!head) return;

    //     while (!st.empty() && st.top()->val < head->val) {
    //         st.pop();
    //     }

    //     st.push(head);
    //     removeNodes(head->next, st);
    // }
    
    // Time: O(n) Space: O(n)
    // ListNode* removeNodes(ListNode* head) {
    //     if (!head) return NULL;
    //     head->next = removeNodes(head->next);
    //     return head->next && head->val < head->next->val ?  head->next : head;
    // }

    // Time: O(n) Space: O(1)
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;

        ListNode *reversedList = reverseLinkedList(head);

        ListNode *temp = reversedList->next;
        ListNode *result = reversedList;
        int currMax = reversedList->val;
        while (temp) {
            if (temp->val >= currMax) {
                result->next = temp;
                result = temp;
                currMax = temp->val;
            } else {
                result->next = temp->next;
            }
            temp = temp->next;
        }
        

        return reverseLinkedList(reversedList);
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
