#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(2^n), Space: O(n)
    vector<string> generateParenthesis(int n) {
        if(!n) return {};
        
        vector<string> result;
        string single_result(n * 2, '*');
        backtrack(result, single_result, n, 0, 0, 0);
        
        return result;
    }
    
    void backtrack(vector<string>& result, string& single_result, int n, int left_bracket, int right_bracket, int idx) {
        if(idx == n * 2) {
            string temp = string(single_result);
            result.push_back(temp);
        }else{
            if(left_bracket < n) {
                single_result[idx] = '(';
                
                backtrack(result, single_result, n, left_bracket + 1, right_bracket, idx + 1);
                
                single_result[idx] = '*';
            }
            
            if(right_bracket < left_bracket) {
                single_result[idx] = ')';
                
                backtrack(result, single_result, n, left_bracket, right_bracket + 1, idx + 1);
                
                single_result[idx] = '*';
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}