#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
    MyLinkedList(): length(0) {
        head = new MyLinkedListNode(-1);
        tail = new MyLinkedListNode(-1);

        head->next = tail;
        tail->prev = head;
    }

    ~MyLinkedList() {
        MyLinkedListNode *temp = head;
        MyLinkedListNode *next = nullptr;

        while (temp) {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }

    int get(int index) {
        MyLinkedListNode *target = getNodeAtIndex(index);

        return target ? target->val : -1;
    }

    void addAtHead(int val) {
        MyLinkedListNode *newNode = new MyLinkedListNode(val);
        MyLinkedListNode *prevHead = head->next;

        newNode->next = prevHead;
        prevHead->prev = newNode;

        head->next = newNode;
        newNode->prev = head;

        length++;
    }

    void addAtTail(int val) {
        MyLinkedListNode *newNode = new MyLinkedListNode(val);
        MyLinkedListNode *prevTail = tail->prev;

        newNode->prev = prevTail;
        prevTail->next = newNode;

        tail->prev = newNode;
        newNode->next = tail;

        length++;
    }

    void addAtIndex(int index, int val) {
        if(index == length) {
            addAtTail(val);
            return;
        }

        MyLinkedListNode *target = getNodeAtIndex(index);

        if (!target) return;

        MyLinkedListNode *newNode = new MyLinkedListNode(val);
        newNode->next = target;
        newNode->prev = target->prev;

        target->prev = newNode;
        newNode->prev->next = newNode;

        length++;
    }

    void deleteAtIndex(int index) {
        MyLinkedListNode *target = getNodeAtIndex(index);

        if (!target) return;

        target->prev->next = target->next;
        target->next->prev = target->prev;

        delete target;

        length--;
    }

private:
    struct MyLinkedListNode{
        int val;
        MyLinkedListNode *next;
        MyLinkedListNode *prev;

        MyLinkedListNode(int val, MyLinkedListNode *next, MyLinkedListNode *prev): val(val), next(next), prev(prev) {}
        MyLinkedListNode(int val): val(val), next(nullptr), prev(nullptr) {}
    };

    MyLinkedListNode *head;
    MyLinkedListNode *tail;
    int length;

private:
    MyLinkedListNode* getNodeAtIndex(int index) {
        if (index >= length || index < 0) return nullptr;

        int end = -1;
        MyLinkedListNode *temp;
        bool startFromEnd = index > (length / 2);
        if (startFromEnd) {
            end = length - index - 1;
            temp = tail->prev;
        } else {
            end = index;
            temp = head->next;
        }

        for (int i = 0; i < end; i++) {
            if (startFromEnd) {
                temp = temp->prev;
            } else {
                temp = temp->next;
            }
        }

        return temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char** argv) {
    return 0;
}
