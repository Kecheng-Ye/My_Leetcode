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
    // Time: O(n), Space: O(1)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return nullptr;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *start, *end;
        ListNode *temp = &dummy;
        int count = 0;
        
        while(temp) {
            if(count == left - 1) {
                start = temp;
            }else if(count == right) {
                end = temp;
            }
            
            temp = temp->next;
            count++;
        }
        
        if(!start) return head;
                
        ListNode *r_head = start->next;
        temp = end->next;
        start->next = reverse(r_head, end);
        r_head->next = temp;
        
        return dummy.next;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *prev, *cur, *next;
        ListNode *end = tail->next;
        prev = nullptr;
        cur = head;
        
        while(cur && cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}