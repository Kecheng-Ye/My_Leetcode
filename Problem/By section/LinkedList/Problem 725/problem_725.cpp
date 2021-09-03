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
    int get_length(ListNode* head) {
        int count = 0;
        
        while(head) {
            head = head->next;
            count ++;
        }
        
        return count;
    }
    
    // Time: O(n), Space: O(1)
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        splitListToParts_helper(result, head, k, get_length(head));
        return result;
    }
    
    void splitListToParts_helper(vector<ListNode*>& result, ListNode* head, int k, int size) {
        if(k == 0) return;

        if(size == 0) {
            result.push_back(nullptr);    
            splitListToParts_helper(result, head, k - 1, size);
            return;
        }

        int cur_length = (size % k == 0) ? size / k : (size / k) + 1;

        ListNode* temp = head;
        for(int i = 0; i < cur_length - 1; i++) {
            temp = temp->next;
        }
        
        ListNode* next_head;
        next_head = temp->next;
        temp->next = nullptr;
        
        result.push_back(head);
        splitListToParts_helper(result, next_head, k - 1, size - cur_length);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}