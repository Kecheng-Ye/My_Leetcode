#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        length = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    ~MyLinkedList() {
        MyLinkedListNode *temp = head;
        MyLinkedListNode *next;
        while(temp) {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= length || index < 0) {
            return -1;
        }
        
        MyLinkedListNode *temp = head;
        
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedListNode *new_node = new MyLinkedListNode(val);
        
        if(!length) {
            tail = new_node;
        }else{
            new_node->next = head;
            head->prev = new_node;
        }
        
        head = new_node;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedListNode *new_node = new MyLinkedListNode(val);
        
        if(!length) {
            head = new_node;
        }else{
            new_node->prev = tail;
            tail->next = new_node;
        }
        
        tail = new_node;
        length++;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > length || index < 0) {
            return;
        }else if(index == length) {
            addAtTail(val);
            return;
        }else if(index == 0) {
            addAtHead(val);
            return;
        }
        
        MyLinkedListNode *temp = head;
        MyLinkedListNode *new_node = new MyLinkedListNode(val);
        
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev     = new_node;
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= length || index < 0) {
            return;
        }
        
        MyLinkedListNode *delete_node = nullptr;
        if(length == 1) {
            delete_node = head;
            head = nullptr;
            tail = nullptr;
        }else if(index == length - 1) {
            delete_node = tail;
            tail = tail->prev;
            tail->next = nullptr;
        }else if(index == 0) {
            delete_node = head;
            head = head->next;
        }else{
            MyLinkedListNode *temp = head;
            
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            
            delete_node = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        
        
        length--;
        delete delete_node;
    }
private:
    struct MyLinkedListNode {
        int val;
        MyLinkedListNode *prev;
        MyLinkedListNode *next;
        
        MyLinkedListNode(int val): val(val), next(nullptr), prev(nullptr) {};
        MyLinkedListNode(int val, MyLinkedListNode *next, MyLinkedListNode *prev): val(val), next(next), prev(prev) {};
    };
    
    int length;
    MyLinkedListNode *head;
    MyLinkedListNode *tail;
    
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
    Solution s;
    
    return 0;
}