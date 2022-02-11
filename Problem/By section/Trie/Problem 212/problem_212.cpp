#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(const auto& str : words) {
            trie.insert(str);
        }
        
        int m = board.size(), n = board[0].size();
        vector<vector<int>> is_visited(m, vector<int>(n, false));
        string temp;
        unordered_set<string> result;
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(trie.root->children[board[i][j] - 'a']) {
                    is_visited[i][j] = true;
                    temp += board[i][j];
                    
                    DFS(board, i, j, trie.root->children[board[i][j] - 'a'], result, temp, is_visited);
                    
                    is_visited[i][j] = false;
                    temp.pop_back();
                }
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }

    
private:
    class Trie {
    public:
        Trie() {
            root = new node();
        }
        
        ~Trie() {
            delete root;
        }
        
        void insert(const string& str) {
            node *temp = root;
            
            for(char c : str) {
                int idx = c - 'a';
                
                if(!temp->children[idx]) {
                    temp->children[idx] = new node();
                }
                
                temp = temp->children[idx];
            }
            
            temp->is_end = true;
        }
        
        struct node {
            node(): children(26, nullptr), is_end(false) {
                
            }
            
            ~node() {
                for(auto child : children) {
                    if(child) delete child;
                }
            }
            
            vector<node*> children;
            bool is_end;
        };
        
        node* root;
    };
    
    void DFS(vector<vector<char>>& board, int x, int y, Trie::node* cur, unordered_set<string>& result, string& temp, vector<vector<int>>& is_visited) {
        if(cur->is_end && !result.count(temp)) {
            result.insert(temp);
        }
        
        for(const auto [x_diff, y_diff] : directions) {
            int new_x = x + x_diff, new_y = y + y_diff;
            
            if(new_x < 0 || new_y < 0 || new_x >= board.size() || new_y >= board[0].size() || is_visited[new_x][new_y] || !cur->children[board[new_x][new_y] - 'a']) continue;
            
            is_visited[new_x][new_y] = true;
            temp.push_back(board[new_x][new_y]);
            
            DFS(board, new_x, new_y, cur->children[board[new_x][new_y] - 'a'], result, temp, is_visited);
            
            is_visited[new_x][new_y] = false;
            temp.pop_back();
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}