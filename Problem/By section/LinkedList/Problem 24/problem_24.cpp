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
    // ListNode* swapPairs(ListNode* head) {
    //     if(head == nullptr || head->next == nullptr) return head;
        
    //     ListNode* next = head->next;
    //     ListNode* next_next = next->next;
    //     next->next = head;
    //     head->next = swapPairs(next_next);
    //     return next;
    // }
    
    // Iterative approach
    // Time: O(n), Space: O(1)
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *prev = nullptr, *cur, *next, *result;
        cur = head;
        next = head->next;
        result = next;
        
        while(cur && next) {
            ListNode *next_next = next->next;
            next->next = cur;
            cur->next = next_next;
            if(prev){
                prev->next = next;
            }
            prev = cur;
            cur = next_next;
            next = (next_next) ? next_next->next : nullptr;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}