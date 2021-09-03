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
    // two pass
    // Time: O(n), Space: O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode dummy(0);
    //     dummy.next = head;
    //     ListNode* temp = head;
    //     int size = 0;
        
    //     while(temp) {
    //         size++;
    //         temp = temp->next;
    //     }
        
    //     size -= n;
    //     temp = &dummy;
    //     while(size > 0) {
    //         size--;
    //         temp = temp->next;
    //     }
        
    //     temp->next = temp->next->next;
        
    //     return dummy.next;
    // }
    
    // one pass
    // Time: O(n), Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        for(int i = 0; i < n + 1; i ++) {
            first = first->next;
        }
        
        while(first) {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        return dummy.next;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}