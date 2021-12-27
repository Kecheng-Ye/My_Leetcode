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
    bool enough_size(ListNode* head, int k) {
        ListNode* temp = head;
        
        for(int i = 0; i < k; i++) {
            if(!temp) return false;
            temp = temp->next;
        }
        
        return true;
    }
    
    // Time: O(n), Space: O(n / k)
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(!head) return head;
        
    //     if(!enough_size(head, k)) return head;
        
    //     ListNode* prev = nullptr, *cur = head, *next = head;
    //     for(int i = 0; i < k; i++) {
    //         next = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;
    //     }
        
    //     head->next = reverseKGroup(cur, k);
    //     return prev;
    // }
    
    // Time: O(n), Space: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        
        int count = 0;
        ListNode* result = head, *prev_head = nullptr;
        
        while(true) {
            if(enough_size(head, k)) {
                ListNode* prev = nullptr, *cur = head, *next = head;
                for(int i = 0; i < k; i++) {
                    next = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                }

                if(!count) result = prev;
                if(prev_head) prev_head->next = prev;

                prev_head = head;
                head = cur;
                count++;   
            }else{
                prev_head->next = head;
                break;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}