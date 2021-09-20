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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;
        
        while(cur) {
            ListNode *prev = dummy;
            
            while(prev->next && prev->next->val <= cur->val) {
                prev = prev->next;
            }
            
            ListNode *next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        
        return dummy->next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}