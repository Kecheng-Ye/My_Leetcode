#include <bits/stdc++.h>

using namespace std;

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times): trie(), freq() {
        root = trie.root;
        cur  = trie.root;

        int n = sentences.size();
        for(int i = 0; i < n; i++) {
            trie.insert(sentences[i]);
            freq[sentences[i]] += times[i];
        }

    }

    vector<string> input(char c) {
        const auto compare = [&](const string& a, const string& b) {
            if(this->freq[a] == this->freq[b]) return a < b;

            return this->freq[a] > this->freq[b];
        };


         if(c == '#') {
            freq[new_input] += 1;
            trie.insert(new_input);
            cur = root;
            new_input = "";
            return {};
        }

        priority_queue<string, vector<string>, function<bool(const string&, const string&)>> pq(compare);
        new_input += c;
        int idx = (c == ' ') ? 26 : c - 'a';
        if(cur) cur = cur->children[idx];
        DFS(cur, pq, new_input);

        vector<string> result;
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        reverse(result.begin(), result.end());
        return result;

    }

private:
    struct node {
        vector<node*> children;
        bool is_end;


        node(): children(27, nullptr), is_end(false) {};
        ~node() {
            for(int i = 0; i < 27; i++) {
                if(children[i])
                    delete children[i];
            }
        }
    };

    class Trie {
    public:
        Trie() {
            root = new node();
        }

        ~Trie() {
            delete root;
        }

        void insert(const string& str) {
            node* temp = root;

            for(const char c : str) {
                int idx = (c == ' ') ? 26 : c - 'a';

                if(!(temp->children[idx])) {
                    temp->children[idx] = new node();
                }

                temp = temp->children[idx];
            }

            temp->is_end = true;
        }

        node* root;
    };

    void DFS(node* cur,  priority_queue<string, vector<string>, function<bool(const string&, const string&)>>& pq, string& temp) {
        if(!cur) {
            return;
        }

        if(cur->is_end) {
            pq.push(temp);
            if(pq.size() > limit) pq.pop();
        }

        for(int i = 0; i < 27; i++) {
            if(!(cur->children[i])) continue;
            node* new_temp = cur->children[i];

            char c = (i < 26) ? (char)('a' + i) : ' ';
            temp += c;
            DFS(new_temp, pq, temp);
            temp.pop_back();
        }
    }

    const int limit = 3;
    Trie trie;
    unordered_map<string, int> freq;
    node* root;
    node* cur;
    string new_input;
};

int main(int argc, char** argv) {
    // Solution s;

    return 0;
}
