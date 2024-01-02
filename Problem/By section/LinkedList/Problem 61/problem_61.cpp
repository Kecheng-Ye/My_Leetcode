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
    int get_len(ListNode* head) {
        int cnt = 0;

        while(head) {
            head = head->next;
            cnt++;
        }

        return cnt;
    }

    // Time: O(n), Space: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        int n = get_len(head);
        if(!n) return nullptr;
        k %= n;
        if(k == 0) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* ans = slow->next;

        slow->next = nullptr;
        fast->next = head;
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
