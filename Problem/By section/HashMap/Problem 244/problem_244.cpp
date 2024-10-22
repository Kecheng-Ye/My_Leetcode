#include <bits/stdc++.h>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict): idxMap() {
        for (int i = 0; i < wordsDict.size(); i++) {
            idxMap[wordsDict[i]].push_back(i);
        }
    }
    
    // Time: O(n)
    int shortest(string word1, string word2) {
        int result = INT_MAX;
        
        int i = 0, j = 0;
        const auto& word1Idxs = idxMap[word1];
        const auto& word2Idxs = idxMap[word2];

        while (i < word1Idxs.size() && j < word2Idxs.size()) {
            result = min(result, abs(word1Idxs[i] - word2Idxs[j]));

            if (word1Idxs[i] > word2Idxs[j]) {
                j++;
            } else {
                i++;
            }
        }

        return result;
    }

    // Time: O(n^2)
    // int shortest(string word1, string word2) {
    //     int result = INT_MAX;
        
    //     for (const auto& i : idxMap[word1]) {
    //         for (const auto& j : idxMap[word2]) {
    //             result = min(result, abs(i - j));
    //         }
    //     }

    //     return result;
    // }

private:
    unordered_map<string, vector<int>> idxMap;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */

int main(int argc, char** argv) {    
    return 0;
}