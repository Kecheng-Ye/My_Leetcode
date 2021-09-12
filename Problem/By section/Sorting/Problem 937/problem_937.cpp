#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Sapce: O(logn)
    // vector<string> reorderLogFiles(vector<string>& logs) {
    //     int n = logs.size();
    //     if(n == 1) return logs;
        
    //     unordered_map<string, log> record;
        
    //     for(int i = 0; i < n; i++) {
    //         string line = logs[i];
    //         record[line] = parse_string(line, i);
    //     }
        
    //     auto compare = [&](const string& str_a, const string& str_b){
    //         log a = record[str_a], b = record[str_b];
                
    //         if(a.type != b.type) return a.type < b.type;
            
    //         if(a.type == 0) {
    //             if(a.content != b.content) return a.content < b.content;

    //             return a.identifier < b.identifier;
    //         }

    //         return a.idx < b.idx;
    //     };
        
    //     vector<string> result(logs);
    //     sort(result.begin(), result.end(), compare);
    //     return result;
    // }
    
    // struct log {
    //     int type; // 0 for letter, 1 for digit
    //     int idx;
    //     string identifier;
    //     string content;
    // };
    
    // log parse_string(const string& input, int idx) {
    //     log result;
    //     result.idx = idx;
        
    //     int first_space = input.find(" ");
    //     result.identifier = string(input.begin(), input.begin() + first_space);
    //     result.content = string(input.begin() + first_space + 1, input.end());
    //     result.type = isdigit(result.content[0]);
        
    //     return result;
    // }
    
    
    // Time: O(nlogn), Sapce: O(logn)
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        if(n == 1) return logs;
        
        
        vector<string> digit_logs;
        vector<pair<int, string>> letter_logs;
        
        for(int i = 0; i < n; i++) {
            int first_space = logs[i].find(" ");
            if(isdigit(logs[i][first_space + 1])) {
                digit_logs.push_back(logs[i]);
            }else{
                letter_logs.push_back({first_space, logs[i]});
            }
        }
        
        sort(letter_logs.begin(), letter_logs.end(), compare); // only need to sort letter logs
                
        vector<string> result(n);
        int m = letter_logs.size();
        
        for(int i = 0; i < n; i++) {
            if(i < m) {
                result[i] = letter_logs[i].second;
            }else{
                result[i] = digit_logs[i - m];
            }
        }
        
        return result;
        
    }
    
    static bool compare(const pair<int, string>& a, const pair<int, string>& b) {
        int size_a = a.second.size();
        int size_b = a.second.size();
        int first_space_a = a.first;
        int first_space_b = b.first;
        
        string a_content = a.second.substr(first_space_a + 1, size_a - first_space_a);
        string b_content = b.second.substr(first_space_b + 1, size_b - first_space_b);
        
        if(a_content != b_content) {
            return a_content <  b_content;
        }else{
            return a.second.substr(0, first_space_a) < b.second.substr(0, first_space_b);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}