#include <bits/stdc++.h>

using namespace std;

class LRU {
public:
    struct Node {
        Node* prev;
        Node* next;
        int key;
        int val;

        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr){};

        friend std::ostream& operator<<(std::ostream& o, const Node& node) {
            return o << "[" << node.key << " " << node.val << "]";
        }
    };

    LRU(int limit) {
        list = Linkedlist();
        fre_map = unordered_map<int, Node*>();
        size_limit = limit;
    }

    Node *get(int key) {
        if(!fre_map.count(key)) return nullptr;

        Node *result = fre_map[key];
        put(result->key, result->val);

        return result;
    }

    void put(int key, int val) {
        Node *new_node = new Node(key, val);
        if(fre_map.count(key)) {
            list.remove(fre_map[key]);
            list.add_first(new_node);
            fre_map[key] = new_node;        
        }else{
            if(list.get_size() == size_limit) {
                int delete_key = list.remove_last();
                fre_map.erase(delete_key);
            }

            list.add_first(new_node);
            fre_map[key] = new_node;
        }
    }

    friend std::ostream& operator<<(std::ostream& o, const LRU& cache) {
        return o << cache.list;
    }

private:
    class Linkedlist {
    public:
        Linkedlist() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void add_first(Node *input) {
            if(size == 0) {
                head = input;
                tail = input;
            }else{
                input->next = head;
                head->prev = input;
                head = input;
            }

            size++;
        }

        void remove(Node *input) {
            if(size == 1) {
                head = nullptr;
                tail = nullptr;
            }else if(input == head) {
                Node* temp = input->next;
                temp->prev = nullptr;
                head = temp;
            }else if(input == tail) {
                Node* temp = input->prev;
                temp->next = nullptr;
                tail = temp;
            }else{
                Node* prev_node = input->prev;
                Node* next_node = input->next;

                prev_node->next = next_node;
                next_node->prev = prev_node;
            }

            delete input;
            size--;
        }

        int remove_last() {
            int cached_key = tail->key;
            remove(tail);

            return cached_key;
        }

        int get_size() {
            return size;
        }

        friend std::ostream& operator<<(std::ostream& o, const Linkedlist& list) {
            Node* iter = list.head;
            o << "{";
            while(iter != list.tail) {
                o << (*iter) << ", ";
                iter = iter->next;
            }

            return o << (*iter) << "}";
        }

    private:
        Node* head;
        Node* tail;
        int size;


    };

    Linkedlist list;
    unordered_map<int, Node*> fre_map;
    int size_limit;
};

int main(int argc, char** argv) {
    // LRU cache(2);
    // cache.put(1, 1);
    // cache.put(2, 2);
    // cout << cache << endl;
    // cache.put(3, 3);
    // cout << cache << endl;
    // cout << (*(cache.get(2))) << endl;

    // string s(6);
    // cout << s << endl;
    return 0;
}