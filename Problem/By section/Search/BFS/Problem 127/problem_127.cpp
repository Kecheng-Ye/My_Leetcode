#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;

        int result = 0;
        int size = beginWord.length();
        queue<string> q;
        unordered_set<string> visited(wordList.begin(), wordList.end());

        if(!visited.count(endWord)) return 0;

        q.push(beginWord);
        visited.erase(beginWord); 

        while(!q.empty()) {
            int this_level = q.size();

            while(this_level) {
                auto temp = q.front();
                q.pop();

                if(temp == endWord) return result + 1;

                // for(const auto& candidate : wordList) {
                //     if(!visited.count(candidate)) continue;

                //     if(valid_transform(temp, candidate)) {
                //         q.push(candidate);
                //         visited.erase(candidate);
                //     }
                // }

                
                for(int i = 0; i < size; i++) {
                    string candidate(temp);
                    for(char j = 'a'; j <= 'z'; j++) {
                        candidate[i] = j;

                        if(!visited.count(candidate)) continue;

                        q.push(candidate);
                        visited.erase(candidate);
                    }
                }

                this_level--;
            }

            result++;
        }

        return 0;
    }

    bool valid_transform(const string& begin, const string& end) {
        int i = 0;

        for(int j = 0; j < begin.length() && i <= 1; j++) {
            if(begin[j] != end[j]) i++;
        }

        return (i == 1);
    }
};

int main(int argc, char** argv) {
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}