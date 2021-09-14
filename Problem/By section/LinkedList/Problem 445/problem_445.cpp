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

    // Post Order Approach
    // Time: O(max(l1.size, l2.size)), Space: O(max(l1.size, l2.size))
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int size_1 = get_length(l1);
    //     int size_2 = get_length(l2);
        
    //     ListNode* dummy = new ListNode(-1);
    //     dummy->next = addTwoNumbers(l1, l2, size_1, size_2);
        
    //     return (dummy->next->val > 0) ? dummy->next : dummy->next->next;
        
    // }
    
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int size_1, int size_2) {
    //     if(!l1 && !l2) {
    //         ListNode* temp = new ListNode(0);
    //         return temp;
    //     }
        
    //     ListNode* after_result;
    //     ListNode* this_result = new ListNode(0); // overhead for carry
    //     if(size_1 > size_2) {
    //         after_result = addTwoNumbers(l1->next, l2, size_1 - 1, size_2);
    //         after_result->val += l1->val;
    //     }else if(size_1 < size_2) {
    //         after_result = addTwoNumbers(l1, l2->next, size_1, size_2 - 1);
    //         after_result->val += l2->val;
    //     }else{
    //         after_result = addTwoNumbers(l1->next, l2->next, size_1 - 1, size_2 - 1);
    //         after_result->val += l2->val + l1->val;
    //     }
        
    //     if(after_result->val >= 10) {
    //         this_result->val = after_result->val / 10;
    //         after_result->val %= 10;
    //     }
        
    //     this_result->next = after_result;
        
    //     return this_result;
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