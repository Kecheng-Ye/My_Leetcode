#include <bits/stdc++.h>

using namespace std;

class Solution {
// private:
//     stack<int> openBracketPos;
//     vector<int> toBeRemoved;
public:
    // Time: O(nlogn), Space: O(n)
    string minRemoveToMakeValid(string s) {
        
        stack<int> openBracketPos;
        vector<int> toBeRemoved;

        // record all brackets that should be removed
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(')
                openBracketPos.push(i);
            else if(s[i] == ')' && openBracketPos.size() > 0)
                openBracketPos.pop();
            else if(s[i] == ')' && openBracketPos.size() == 0)
                toBeRemoved.push_back(i);
        } 
        while(openBracketPos.size() > 0) {
            toBeRemoved.push_back(openBracketPos.top()); 
            openBracketPos.pop();
        }

        // sort them in descending order so you can delete them without messing the relative order
        std::sort(toBeRemoved.begin(), toBeRemoved.end(), [](int& l , int& r) {return l > r;});

        for( int pos : toBeRemoved) {
            s.erase(pos, 1);
        }
        return s; 
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}