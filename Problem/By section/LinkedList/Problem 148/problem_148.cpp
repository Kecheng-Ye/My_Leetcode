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
    // Time: O(nlogn), Space: O(1)
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int size = 0;
        ListNode *temp = head;
        while(temp) {
            temp = temp->next;
            size++;
        }
        
        ListNode dummy(0, head);
        ListNode *tail;
        ListNode *l, *r, *cur;
        
        for(int i = 1; i < size; i <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            
            while(cur) {
                l = cur;
                r = split(cur, i);
                cur = split(r, i);
                
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        
        return dummy.next;
    }
    

private:
    ListNode *split(ListNode *head, int n) {
        ListNode *temp = head;
        while(--n && temp) {
            temp = temp->next;
        }
        
        ListNode *next = (temp) ? temp->next : nullptr;
        if(temp) {
            temp->next = nullptr;
        }
        
        return next;
    }
    
    pair<ListNode*, ListNode*> merge(ListNode* left, ListNode *right) {
        if(!right) return {left, nullptr};
        
        ListNode dummy(0);
        ListNode *temp = &dummy;
        
        while(left && right) {
            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        
        if(!left) {
            temp->next = right;
        }else if(!right) {
            temp->next = left;
        }
        
        ListNode *tail = temp;
        while(tail->next) {
            tail = tail->next;
        }
        
        return {dummy.next, tail};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}