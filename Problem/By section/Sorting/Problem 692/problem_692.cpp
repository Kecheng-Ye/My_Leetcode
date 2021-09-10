#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlog(k)), Space: O(n)
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        for(const auto& word : words) {
            freq[word]++;
        }
        
        auto compare = [&](const string& a, const string& b) {
            if(freq[a] == freq[b]) return a < b;
        
            return freq[a] > freq[b];
        };
        
        priority_queue<string, vector<string>, decltype(compare)> q(compare);
        
        for(const auto& pair_word : freq) {
            string word = pair_word.first;
            q.push(word);
            if(q.size() > k) q.pop();
        }
        
        vector<string> result(k);
        while(k-- > 0) {
            result[k] = q.top();
            q.pop();
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}