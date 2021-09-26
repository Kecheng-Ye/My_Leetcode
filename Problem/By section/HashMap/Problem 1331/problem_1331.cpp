#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(!n) return {};
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> ranks;
        int rank = 1;
        for(int i = 0; i < n; i++) {
            while(i + 1 < n && temp[i] == temp[i + 1]) {
                i++;
            }
            
            ranks[temp[i]] = rank++;
        }
        
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = ranks[arr[i]];
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}