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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        do{
            if(!fast || !fast->next) return nullptr;
            
            fast = fast->next->next;
            slow = slow->next;
        }while(slow != fast);
        
        fast = head;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}