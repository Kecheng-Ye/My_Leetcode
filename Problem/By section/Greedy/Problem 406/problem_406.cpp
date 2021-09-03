#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool sortcol(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    
    // Time: O(n^2), Space: O(n)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size() == 0) return vector<vector<int>>{};

        sort(people.begin(), people.end(), sortcol);

        vector<vector<int>> result(people.size());
        int cnt = 0;
        
        for(auto person : people) {
            for(int i = cnt; i > person[1]; i--) {
                result[i] = result[i - 1];
            }
            
            cnt++;
            result[person[1]] = person;
        }
        

        return result;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}