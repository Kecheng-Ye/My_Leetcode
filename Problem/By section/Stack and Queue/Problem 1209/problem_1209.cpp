#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    // string removeDuplicates(string& s, int k) {
    //     int n = s.size();
        
    //     if(n < k) return s;
        
    //     stack<pair<char, int>> st;
    //     bool has_del = false;
        
    //     for(int i = 0; i < n; i++) {
    //         char cur = s[i];
    //         if(!st.empty() && st.top().first == cur) {
    //             st.top().second += 1;
                
    //             if(st.top().second == k)  {
    //                 has_del = true;
    //                 st.pop();
    //             }
                
    //         }else{
    //             st.push({cur, 1});
    //         }
    //     }
        
    //     string result;
    //     while(!st.empty()) {
    //         auto cur = st.top();
    //         st.pop();
            
    //         result = string(cur.second, cur.first) + result;
    //     }
        
    //     // dont need to do it again !!!!
    //     // the nature of stack solve it
    //     // if(has_del) {
    //     //     return removeDuplicates(result, k);
    //     // }else{
    //     //     return result;
    //     // }
        
    //     return result;
    // }
    
    // slow ptr = j, fast ptr = i;
    string removeDuplicates(string s, int k) {
        auto j = 0;
        stack<int> counts;
        for (auto i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if (j == 0 || s[j] != s[j - 1]) {
                counts.push(1);
            } else if (++counts.top() == k) {
                counts.pop();
                j -= k;
            }
        }
        return s.substr(0, j);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}