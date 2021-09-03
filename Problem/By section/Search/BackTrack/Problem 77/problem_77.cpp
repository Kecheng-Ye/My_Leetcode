#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(!n || !k) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<int> single_result;

        backtrack(result, single_result, 1, n, k);

        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& single_result, int start, int end, int left) {
        if(left == 0) {
            result.push_back(single_result);
        }else{
            
            for(int i = start; i < end + 1; i++) {
                single_result.push_back(i);

                backtrack(result, single_result, i + 1, end, left - 1);

                single_result.pop_back();
            }
            
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    vector<string> lst;
    string a = "lalalala";
    lst.push_back(a);
    a += "popp";
    cout << lst[0] << endl;


    return 0;
}