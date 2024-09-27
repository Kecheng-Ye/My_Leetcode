#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^3), Space: O(n + m)
    // dp[i]: the least amount of extra character for s[:i] with dictionary
    // dp[i] = arg_max_j (dp[j] if s[j:i] in dictionary) or dp[i - 1] + 1
    //                    find possible decomposition     or  skip this char
    // int minExtraChar(string s, vector<string>& dictionary) {
    //     const int n = s.size();
    //     unordered_set<string> dict(dictionary.begin(), dictionary.end());

    //     vector<int> dp(n + 1);
        
    //     for (int i = 1; i <= n; i++) {
    //         dp[i] = 1 + dp[i - 1];
    //         for (int j = i - 1; j >= 0; j--) {
    //             if (dict.count(s.substr(j, i - j))) {
    //                 dp[i] = min(dp[i], dp[j]);
    //             }
    //         }
    //     }

    //     return dp[n];
    // }


    // Time: O(n^2) Space: O(n + m)
    int minExtraChar(string s, vector<string>& dictionary) {
        const int n = s.size();
        Trie trie;
        for (const auto& s : dictionary) {
            trie.insert(s);
        }

        // we flip the dp
        // dp[i]: minium extra char for s[i:n]
        vector<int> dp(n + 1);
        Trie::TreeNode *root = trie.root;
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            Trie::TreeNode *temp = root;
            dp[i] = 1 + dp[i + 1];
            // try to search any substr from s[i : n] can form a word from dict
            for (int j = i; j < n; j++) {
                // s[i:j] cannot form any valid prefix within dictionary
                // thus terminate early
                if (!temp->children[s[j] - 'a']) {
                    break;
                }

                temp = temp->children[s[j] - 'a'];
                
                // s[i:j] is a valid word within dict
                if (temp->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }

private:
    class Trie {
    public:
        Trie() {
            root = new TreeNode();
        }

        ~Trie() {
            delete root;
        }

        void insert(const string& s) {
            TreeNode* temp = root;
            for (const char c : s) {
                if (!temp->children[c - 'a']) {
                    temp->children[c - 'a'] = new TreeNode();
                }
                temp = temp->children[c - 'a'];
            }
            temp->isEnd = true;
        }

        class TreeNode {
        public:
            TreeNode(): children(26, nullptr), isEnd(false) {}

            ~TreeNode() {
                for (TreeNode* child : children) {
                    if (child) {
                        delete child;
                    }
                }
            }

            vector<TreeNode*> children;
            bool isEnd;
        };

        TreeNode* root;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}