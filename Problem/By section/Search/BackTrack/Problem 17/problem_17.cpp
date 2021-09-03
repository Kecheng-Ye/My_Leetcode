#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, string> keyboard = {{'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"}, 
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}};

    vector<string> letterCombinations(string digits) {
        string single_result = "";
        vector<string> result;

        backtrack(digits, result, single_result, 0);

        return result;
    }

    void backtrack(string& digits, vector<string>& result, string& single_result, int idx) {
        if(idx == digits.length()) {
            string temp(single_result);
            result.push_back(temp);
        }else {
            string search_space = keyboard[(digits[idx])];

            for(auto& i : search_space) {
                single_result += i;

                backtrack(digits, result, single_result, idx + 1);

                single_result.pop_back();
            }
        }

        return;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // cout << s.keyboard['9'] << endl;
    string test = "lalalalal";
    test.pop_back();
    cout << test << endl;
    return 0;
}