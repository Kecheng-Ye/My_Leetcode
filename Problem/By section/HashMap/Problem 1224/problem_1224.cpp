#include <bits/stdc++.h>

using namespace std;

class Leaderboard {
public:
    // Space: O(n)
    Leaderboard(): board(), bst() {

    }

    // Time: O(logn)
    void addScore(int playerId, int score) {
        if (!board.count(playerId)) {
            insert_new_score(playerId, score);
        } else {
            const auto it = board[playerId];
            int new_score = *it + score;
            bst.erase(it);
            insert_new_score(playerId, new_score);
        }
    }

    // Use reverse iterator in BST to iterate the K biggest elements
    // Time: O(K)
    int top(int K) {
        int result = 0;
        int k = K;
        for(auto it = bst.rbegin(); it != bst.rend() && k > 0; k--, it++) {
            result += *it;
        }

        return result;
    }

    // Time: O(logn)
    void reset(int playerId) {
        const auto it = board[playerId];
        bst.erase(it);
        insert_new_score(playerId, 0);
    }

private:
    void insert_new_score(int playerId, int score) {
        const auto it = bst.insert(score);
        board[playerId] = it;
    }

    unordered_map<int, multiset<int>::iterator> board;
    multiset<int> bst;
};

int main(int argc, char** argv) {
    return 0;
}
