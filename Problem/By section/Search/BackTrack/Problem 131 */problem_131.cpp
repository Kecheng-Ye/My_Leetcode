#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(2^n), Space: O(n)
//     vector<vector<string>> partition(string s) {
//         int size = s.size();
//         if(size == 0) return vector<vector<string>>();

//         vector<vector<string>> result;
//         vector<string> single_result;
//         backtrack(result, s, single_result, 0);

//         return result;
//     }

//     void backtrack(vector<vector<string>>& result, string& s, vector<string>& single_result, int start_idx) {
//         int end = s.size();
//         if(start_idx == end) {
//             result.push_back(single_result);
//         }else{
//             for(int i = start_idx; i < end; i++) {
//                 if(is_palindrome(s, start_idx, i)) {
//                     single_result.push_back(s.substr(start_idx, (i - start_idx) + 1));

//                     backtrack(result, s, single_result, i + 1);

//                     single_result.pop_back();
//                 }
//             }
//         }
//     }

//     bool is_palindrome(string& s, int start, int end) {
//         int i = start, j = end;

//         while(i <= j) {
//             if(s[i] != s[j]) return false;
            
//             i++;
//             j--;
//         }

//         return true;
//     }
// };

class Solution {
public:
    // Use DP to accelerate 
    // Time: O(2^n * n), Space: O(n * n)
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    string str = "aaaa";
    cout << str.substr(2, 3 - 2 + 1) << endl;
    return 0;
}