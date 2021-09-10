#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        // since there are only 26 letters
        // we can simplify a hashmap representation of letter dict for each word into a 32 bit integer
        // where each bit represents if this word has this letter or not 
        vector<int> dictionary(n, 0);
        
        for(int i = 0; i < n; i++) {
            string word = words[i];
            for(const auto& c : word) {
                dictionary[i] |= (1 << (c - 'a'));  // has to use or not plus, because we will corrupt other bit if we use plus
            }
        }
        
        long long result = 0;
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if((dictionary[i] & dictionary[j]) == 0) {
                    result = max(result, (long long)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}