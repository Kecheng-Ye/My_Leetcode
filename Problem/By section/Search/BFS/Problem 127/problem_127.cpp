#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(n), Space: O(n)
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         if(beginWord == endWord) return 0;

//         int result = 0;
//         int size = beginWord.length();
//         queue<string> q;
//         unordered_set<string> visited(wordList.begin(), wordList.end());

//         if(!visited.count(endWord)) return 0;

//         q.push(beginWord);
//         visited.erase(beginWord); 

//         while(!q.empty()) {
//             int this_level = q.size();

//             while(this_level) {
//                 auto temp = q.front();
//                 q.pop();

//                 if(temp == endWord) return result + 1;

//                 // for(const auto& candidate : wordList) {
//                 //     if(!visited.count(candidate)) continue;

//                 //     if(valid_transform(temp, candidate)) {
//                 //         q.push(candidate);
//                 //         visited.erase(candidate);
//                 //     }
//                 // }

                
//                 for(int i = 0; i < size; i++) {
//                     string candidate(temp);
//                     for(char j = 'a'; j <= 'z'; j++) {
//                         candidate[i] = j;

//                         if(!visited.count(candidate)) continue;

//                         q.push(candidate);
//                         visited.erase(candidate);
//                     }
//                 }

//                 this_level--;
//             }

//             result++;
//         }

//         return 0;
//     }

//     bool valid_transform(const string& begin, const string& end) {
//         int i = 0;

//         for(int j = 0; j < begin.length() && i <= 1; j++) {
//             if(begin[j] != end[j]) i++;
//         }

//         return (i == 1);
//     }
// };

class Solution {
public:
    // Bidirectional BFS
    // Time: O(m^2 * n^(1/2)), Space: O(nm)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return 0;

        queue<string> q1;
        unordered_set<string> isVisited1;

        q1.push(beginWord);
        isVisited1.insert(beginWord);

        queue<string> q2;
        unordered_set<string> isVisited2;

        q2.push(endWord);
        isVisited2.insert(endWord);

        int step = 0;

        while (!q1.empty() && !q2.empty()) {
            int currLvl = q1.size();
            step++;

            while (currLvl--) {
                const string currWord = q1.front(); q1.pop();

                if (isVisited2.count(currWord)) return step;

                for (const string& candidate : wordList) {
                    if (canChange(currWord, candidate) && !isVisited1.count(candidate)) {
                        q1.push(candidate);
                        isVisited1.insert(candidate);
                    }
                }
            }

            swap(q1, q2);
            swap(isVisited1, isVisited2);
        }

        return 0;
    }

private:
    bool canChange(const string& a, const string& b) {
        int changeCount = 0;
        for (int i = 0; i < a.size() && (changeCount < 2); i++) {
            changeCount += (a[i] != b[i]);
        }

        return changeCount < 2;
    }
};

int main(int argc, char** argv) {
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}