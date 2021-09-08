/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // time: O(n), space: O(n)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast != NULL) {
            if(fast->next == NULL) {
                break;
            }
            
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);

    a.next = &b;
    b.next = &c;
    c.next = &a;
    
    // int count = 10;
    // ListNode *temp = &a;
    // while(count-- >= 0) {
    //     std::cout << temp->val << std::endl;
    //     temp = temp->next;
    // }

    Solution solution;
    std::cout << solution.hasCycle(&a) << std::endl;
    // std::cout << (-8 % 7) << std::endl;
}