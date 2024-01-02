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
    // ListNode* reverse(ListNode* head) {
    //     ListNode *prev = nullptr, *cur = head, *next = head;

    //     while(cur) {
    //         next = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;
    //     }

    //     return prev;
    // }

    // int get_length(ListNode* head) {
    //     int count = 0;

    //     while(head) {
    //         count ++;
    //         head = head->next;
    //     }

    //     return count;
    // }

    // // cut the ListNode into half
    // // reverse the second half, and start comparing
    // // Time: O(n), Space: O(1)
    // bool isPalindrome(ListNode* head) {
    //     int n = get_length(head);
    //     int mid_point = (n / 2);

    //     ListNode* temp = head;
    //     for(int i = 0; i < mid_point; i++) {
    //         temp = temp->next;
    //     }

    //     ListNode* back = reverse(temp);
    //     temp = head;
    //     for(int i = 0; i < mid_point; i++) {
    //         if(temp->val != back->val) return false;

    //         temp = temp->next;
    //         back = back->next;
    //     }

    //     return true;
    // }


    ListNode *left;
    // one pass, recursive
    // Time: O(n), Space: O(n)
    bool isPalindrome(ListNode* head){
        left = head;
        return isPalindrome_helper(head);
    }

    bool isPalindrome_helper(ListNode* right){
        if(right == nullptr) return true;

        if(!(isPalindrome_helper(right->next) && (left->val == right->val))) return false;
        left = left->next;
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
