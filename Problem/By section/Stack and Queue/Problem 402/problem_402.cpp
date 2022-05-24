#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    string removeKdigits(string num, int k) {
        int n = num.size();
        deque<char> dq;
        dq.push_back(num[0]);
        
        for(int i = 1; i< n; i++) {
            while(dq.size() && k > 0 && dq.back() > num[i]) {
                dq.pop_back();
                k--;
            }
            
            dq.push_back(num[i]);
        }
        
        while(k--) {
            dq.pop_back();
        }
        
        string result;
        while(!dq.empty()) {
            char cur = dq.front();
            dq.pop_front();
            if(result.size() == 0 && cur == '0') continue;
            
            result += cur;
        }
        
        return (result.size()) ? result : "0";
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}