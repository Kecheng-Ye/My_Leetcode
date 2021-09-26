#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if(n == 1) return "/";
        
        stack<string> s;
        
        for(int i = 0; i < n; i++) {
            if(path[i] == '/') {
                continue;
            }else{
                int num_char = 0;
                while(i + num_char < n && path[i + num_char] != '/') {
                    num_char++;
                }
                
                string temp = path.substr(i, num_char);
                
                if(temp == ".") {
                    continue;
                }else if(temp == "..") {
                    if(!s.empty()) {
                        s.pop();
                    }
                }else{
                    s.push(temp);
                    i += num_char - 1;  
                }
            }
        }
        
        string result = "";
        if(s.empty()) {
            result = "/";
        }else{
            while(!s.empty()) {
                result = "/" + s.top() + result;
                s.pop();
            }
           
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}