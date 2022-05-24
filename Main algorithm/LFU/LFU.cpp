#include <bits/stdc++.h>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity): record(), freq_lst(), capacity(capacity), min_freq(0) {
        
    }
    
    int get(int key) {
        if(!record.count(key)) return -1;
        
        update(key);
        return record[key]->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if(record.count(key)) {
            record[key]->val = value;
            update(key);
        }else{
            if(record.size() == capacity) {
                int key = freq_lst[min_freq].remove_last();
                record.erase(key);
                
                if(freq_lst[min_freq].get_size() == 0) {
                    freq_lst.erase(min_freq);
                }   
            }
            
            min_freq = 1;
            Node *new_node = new Node(key, value, 1);
            record[key] = new_node;
            freq_lst[min_freq].add_first(new_node);
        }
    }
    
private:
    void update(int key) {
        Node *target = record[key];
        
        freq_lst[target->freq].remove(target, false);
        if(freq_lst[target->freq].get_size() == 0 && min_freq == target->freq) {
            freq_lst.erase(target->freq);
            min_freq++;
        }
        
        target->freq++;
        freq_lst[target->freq].add_first(target);
    }
    
    struct Node {
		Node* prev;
		Node* next;
		int key;
		int val;
        int freq;

		Node(int key, int val, int freq) : key(key), val(val), freq(freq), prev(nullptr), next(nullptr){};
	};
    
    class Linkedlist {
	public:
		// fix a useless head and tail
		// that makes the insert and delete much easier
	    Linkedlist() {
			head = new Node(-1, -1, -1);
			tail = new Node(-1, -1, -1);
			head->next = tail;
			tail->prev = head;
			size = 0;
		}

		~Linkedlist() {
			Node* cur = head, *next = nullptr;
            
            while(cur) {
                next = cur->next;
                delete cur;
                cur = next;
            }
		}

        Node* get_last() {
            if(!size) return nullptr;
            
            return tail->prev;
        }
        
		void add_first(Node *input) {
			input->prev = head;
			input->next = head->next;

			head->next->prev = input;
			head->next = input;

			size++;
		}

		void remove(Node *input, bool reclaim = true) {
			Node* prev = input->prev;
			Node* next = input->next;
			prev->next = next;
			next->prev = prev;

			if(reclaim) delete input;
			size--;
		}

		int remove_last() {
			int cached_key = tail->prev->key;
			remove(tail->prev);

			return cached_key;
		}

		void move_to_head(Node* node) {
			remove(node, false);
			add_first(node);
		}

		int get_size() {
			return size;
		}

	private:
		Node* head;
		Node* tail;
		int size;
	};
    
    unordered_map<int, Node*> record;
    unordered_map<int, Linkedlist> freq_lst;
    int capacity;
    int min_freq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char** argv) {
    return 0;
}