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
    // int get_length(ListNode* l1) {
    //     int count = 0;
        
    //     while(l1) {
    //         count++;
    //         l1 = l1->next;
    //     }
        
    //     return count;
    // }

    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int size_1 = get_length(l1);
    //     int size_2 = get_length(l2);
        
    //     ListNode* dummy = new ListNode(-1);
        
    //     dummy->next = addTwoNumbers(l1, l2, size_1, size_2, max(size_1, size_2));
    //     if(dummy->next->val >= 10) {
    //         dummy->next->val %= 10;
    //         dummy->val = 1;
    //         return dummy;
    //     }else{
    //         return dummy->next;
    //     }
    // }
    
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int size_1, int size_2, int index) {
    //     if(!l1 && !l2) return nullptr;
    //     ListNode* result;
    //     if(size_1 < index) {
    //         result = new ListNode(l2->val);
    //         l2 = l2->next;
    //         size_2 -= 1;
    //     }else if(size_2 < index) {
    //         result = new ListNode(l1->val);
    //         l1 = l1->next;
    //         size_1 -= 1;
    //     }else{
    //         result = new ListNode(l1->val + l2->val);
    //         l1 = l1->next;
    //         l2 = l2->next;
    //         size_1 -= 1;
    //         size_2 -= 1;
    //     }
        
    //     index -= 1;
    //     result->next = addTwoNumbers(l1, l2, size_1, size_2, index);
    //     if(result->next && result->next->val >= 10) {
    //         result->next->val %= 10;
    //         result->val += 1;
    //     }
    //     return result;
    // }
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> list_1 = linkedlist_to_stack(l1);
        stack<int> list_2 = linkedlist_to_stack(l2);

        ListNode *dummy = new ListNode(-1);
        int carry = 0;

        while(!list_1.empty() || !list_2.empty() || carry != 0) {
            if(!list_1.empty()) {
                carry += list_1.top();
                list_1.pop();
            }

            if(!list_2.empty()) {
                carry += list_2.top();
                list_2.pop();
            }

            ListNode *node = new ListNode(carry % 10);
            node->next = dummy->next;
            dummy->next = node;
            carry /= 10;
        }

        return dummy->next;
    }

    stack<int> linkedlist_to_stack(ListNode* head) {
        stack<int> result;

        while(head) {
            result.push(head->val);
            head = head->next;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}