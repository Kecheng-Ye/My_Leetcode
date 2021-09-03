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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = head;
        if(!odd_head) return nullptr;
        ListNode* even_head = head->next;
        
        ListNode *odd = odd_head, *even = even_head;
        
        while(even && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        
        odd->next = even_head;
        return head;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}