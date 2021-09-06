#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // intuition: [i, j, val] = (result[i : end] + val) + (result[j + 1 : end] - val)
    // n = length, k = len(updates)
    // Time: O(n + k), Space: O(1)
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        if(!n) return vector<int>(length); 
        vector<int> result(length);
        
        for(int i = 0; i < n; i++) { // only need to update two boarder of the array
            result[updates[i][0]] += updates[i][2];
            if(updates[i][1] < length - 1) {
                result[updates[i][1] + 1] -= updates[i][2];
            }
        }
        
        int carry = 0;
        for(int i = 0; i < length; i++) {
            result[i] += carry;
            carry = result[i];
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}