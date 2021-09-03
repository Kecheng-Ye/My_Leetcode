#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(3^(n/3)), Space: O(n)
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string single_result = "";

        backtrack(s, result, single_result, 0, 0, s.length());
        return result;
    }

    void backtrack(string original, vector<string>& result, string& single_result, int index, int num_ip, int size) {
        if(index >= size && num_ip == 4) {
            string temp(single_result.begin(), single_result.end() - 1);
            result.push_back(temp);
        }else if(num_ip > 4 || index >= size){
            return;
        }else{
            int answer_size = single_result.length();

            for(int i = 0; i < 3 && index + i < size; i++) {
                auto begin = original.begin() + index;
                auto end = begin + i + 1;
                string sub = string(begin, end) + ".";

                if(i == 2 && stoi(sub) > 255) {
                    break;
                }

                single_result += sub;
                backtrack(original, result, single_result, index + i + 1, num_ip + 1, size);
                single_result.erase(single_result.begin() + answer_size, single_result.end());

                if(sub == "0.") break;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    // string a = "abc";
    // int size = a.size();
    // a += "cb";
    // cout << a << endl;
    // a.erase(a.begin() + size, a.end());
    // cout << string(a.begin(), a.begin()) << endl;

    return 0;
}