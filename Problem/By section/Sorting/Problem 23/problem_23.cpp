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
    static bool compare(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
    
    // Time: O(Nlogk), Space: O(k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(!n) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, function<bool(const ListNode*, const ListNode*)>> pq(compare);
        
        for(auto root : lists) {
            if(root) pq.push(root);
        }
        
        ListNode dummy;
        ListNode* cur_ptr = &dummy;
        
        while(!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            cur_ptr->next = smallest;
            if(smallest->next) pq.push(smallest->next);
            // smallest->next = nullptr;
            cur_ptr = cur_ptr->next;
        }
        
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}