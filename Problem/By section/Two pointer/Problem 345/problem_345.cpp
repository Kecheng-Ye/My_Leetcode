#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        string result(s);

        while(left < right) {
            if(vowels.find(s[left]) == vowels.end()) {
                left ++;
            }else if(vowels.find(s[right]) == vowels.end()){
                right --;
            }else {
                char temp = s[left];
                result[left++] = s[right];
                result[right--] = temp;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    std::cout << solution.reverseVowels("leetcode") << std::endl;
    return 0;
}