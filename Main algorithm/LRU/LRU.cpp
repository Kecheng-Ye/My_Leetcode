#include <bits/stdc++.h>

using namespace std;

class LRUCache {
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

    LRUCache(int limit) {
		list = Linkedlist();
		fre_map = unordered_map<int, Node*>();
		size_limit = limit;
	}

	int get(int key) {
		if(!fre_map.count(key)) return -1;

		Node *result = fre_map[key];
		put(result->key, result->val);

		return result->val;
	}

	void put(int key, int val) {
		if(fre_map.count(key)) {
			fre_map[key]->val = val;
			list.move_to_head(fre_map[key]);
		}else{
			Node *new_node = new Node(key, val);
			if(list.get_size() == size_limit) {
				int delete_key = list.remove_last();
				fre_map.erase(delete_key);
			}

			list.add_first(new_node);
			fre_map[key] = new_node;
		}
	}

	friend std::ostream& operator<<(std::ostream& o, const LRUCache& cache) {
		return o << cache.list;
	}

private:
	class Linkedlist {
	public:
	    Linkedlist() {
			head = new Node(-1, -1);
			tail = new Node(-1, -1);
			head->next = tail;
			tail->prev = head;
			size = 0;
		}

		~Linkedlist() {
			Node* temp = tail->prev, *prev_node = nullptr;

			while(temp != head) {
				prev_node = temp->prev;
				delete temp;
				temp = prev_node;
			}

			delete head;
			delete tail;
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
    // LRUCache cache(2);
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