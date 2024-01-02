#include <bits/stdc++.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_indent(int num) {
    for(int i = 0; i < num; i++) {
        cout << "\t";
    }
}

int tab = 0;

// class Solution {
// public:
//     // Won't work, because both head will eventually meet on any point that they merge together
//     // but not necessary the way they start to meet
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         // print_indent(tab++);
//         // cout << "Enter with" << " " << ((headA == NULL) ? 0 : headA->val) << " " << ((headB == NULL) ? 0 : headB->val) << endl;

//         if(headA == NULL || headB == NULL) {
//             // print_indent(--tab);
//             // cout << "Exit when meeting nullptr" << endl;
//             return NULL;
//         }

//         if(headA == headB) {
//             // print_indent(--tab);
//             // cout << "find identical head!!!" << endl;
//             ListNode *ans = headA;
//             return ans;
//         }

//         ListNode *ans_1 = getIntersectionNode(headA->next, headB);
//         if(ans_1 != NULL) {
//             // print_indent(--tab);
//             // cout << "find head!!!" << endl;
//             return ans_1;
//         }

//         ans_1 = getIntersectionNode(headA, headB->next);
//         if(ans_1 != NULL) {
//             // print_indent(--tab);
//             // cout << "find head!!!" << endl;
//             return ans_1;
//         }

//         // print_indent(--tab);
//         // cout << "No head found with " << ((headA == NULL) ? 0 : headA->val) << " " << ((headB == NULL) ? 0 : headB->val) << endl;
//         return NULL;
//     }
// };

class Solution {
public:
    // List A length = a(individual part) + c(intersection part)
    // List B length = b(individual part) + c(intersection part)
    // so a + c + b = b + c + a which is the intersection part
    // if no intersection then
    // a + b = b + a, both reach end points
    // Time: O(m + n), Space: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp_A = headA, *temp_B = headB;
        while(temp_A != temp_B) {
            temp_A = (temp_A == NULL) ? headB : temp_A->next;
            temp_B = (temp_B == NULL) ? headA : temp_B->next;
        }
        return temp_A;
    }
};

int main(int argc, char** argv) {
    Solution s;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode A(5);
    ListNode B(6);
    ListNode C(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    A.next = &B;
    B.next = &C;
    C.next = &c;

    s.getIntersectionNode(&a, &A);

    return 0;
}
