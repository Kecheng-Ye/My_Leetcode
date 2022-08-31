#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        if(s.length() == 0) return result;

        for(auto candidate : dictionary) {
            if(candidate.length() < result.length()) continue;

            if(string_truncate(s, candidate)) {
                if(result.length() == candidate.length()) {
                    result = (result < candidate) ? result : candidate;
                }else if(result.length() < candidate.length()){
                    result = candidate;
                }
            }
        }

        return result;
    }

    bool string_truncate(string original, string target) {
        int ptr_ori = 0;
        int ptr_tar = 0;

        while(ptr_ori < original.length() && ptr_tar < target.length()) {
            if(original[ptr_ori++] == target[ptr_tar]) {
                ptr_tar++;
            }
        }

        return ptr_tar == target.length();
    }
};


int main(int argc, char** argv) {
    Solution solution;
    string s = "abpcplea";
    vector<string> dictionary{"ale","apple","monkey","plea"};
    std::cout << solution.findLongestWord(s, dictionary) << std::endl;

    return 0;
}
