#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        if(n == 1) return names;
        unordered_map<string, int> record;
        
        for(int i = 0; i < n; i++) {
            string result = names[i];
            
            if(record.count(result)) {
                int cur = record[names[i]];
                int n = result.size();
                
                while(record.count((result = names[i] + "(" + to_string(cur++) + ")")))
                    ;
                
                record[result]++;
            }
            
            record[names[i]]++;
            names[i] = result;
        }
        
        return names;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}