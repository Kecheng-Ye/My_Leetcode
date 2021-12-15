#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     string countOfAtoms(string formula) {
//         int idx = 0;
//         auto record = helper(formula, idx);
        
//         vector<pair<string, int>> arr;
//         for(const auto& ele_pair : record) {
//             arr.push_back(ele_pair);
//         }
        
//         sort(arr.begin(), arr.end(), [&](const pair<string, int>& a, const pair<string, int>& b){return a.first < b.first;});
//         string result = "";
        
//         for(const auto& ele_pair : arr) {
//             result += (ele_pair.first + ((ele_pair.second > 1) ? to_string(ele_pair.second) : ""));
//         }
        
//         return result;
//     }
    
//     unordered_map<string, int> helper(string& formula, int& idx) {
//         int n = formula.size();
//         if(idx >= n) return unordered_map<string, int>();
        
//         unordered_map<string, int> record;
//         stack<pair<string, int>> s;
        
//         auto isUpper = [&](char c) {return ((c - 'A') >= 0 && (c - 'A') < 26);};
//         string cur_ele = "";
//         int ele_num = 0;        
//         int multiplyer = 1;
        
//         while(idx < n) {
//             if(isalpha(formula[idx])) {
//                 if(isUpper(formula[idx])) {
//                     if(cur_ele != "") {
//                         s.push({cur_ele, max(ele_num, 1)});
//                     }
//                     ele_num = 0;
//                     cur_ele = formula[idx];
//                 }else{
//                     cur_ele += formula[idx];
//                 }
//             }else{
//                 if(formula[idx] == '(') {
//                     if(cur_ele != "") {
//                         s.push({cur_ele, max(ele_num, 1)});
//                         ele_num = 0;
//                         cur_ele = "";
//                     }
//                     idx++;
//                     auto bracket_rec = helper(formula, idx);
//                     for(const auto& ele_pair : bracket_rec) {
//                         auto [ele, num] = ele_pair;
//                         record[ele] += num;
//                     }
//                 }else if(formula[idx] == ')') {
//                     if(cur_ele != "") {
//                         s.push({cur_ele, max(ele_num, 1)});
//                         ele_num = 0;
//                         cur_ele = "";
//                     }
//                     multiplyer = 0;
//                     idx++;
//                     while(idx < n && (formula[idx] - '0') <= 10 && (formula[idx] - '0') >= 0) {
//                         multiplyer = multiplyer * 10 + (int)(formula[idx++] - '0');
//                     }
                    
//                     idx--;
//                     break;
//                 }else{
//                     ele_num = ele_num * 10 + (int)(formula[idx] - '0');
//                 }
//             }
            
//             idx++;
//         }
        
//         if(idx == n && cur_ele != "") {
//             s.push({cur_ele, max(1, ele_num)});
//         }
        
//         while(!s.empty()) {
//             const auto one_ele = s.top();
//             s.pop();
//             record[one_ele.first] += one_ele.second; 
//         }
        
//         for(auto& ele_pair : record) {
//             ele_pair.second *= max(1, multiplyer);
//         }
        
//         return record;
//     }
// };

struct Token {
    string name;
    int val;
};

class Solution {
    // Extract an element beginning with a capital letter and increment the index
    auto extractName(const string& formula, int& i) {
        string name;
        name.push_back(formula[i++]);
        while (i < formula.size() && islower(formula[i])) {
            name.push_back(formula[i++]);
        }
        
        return name;
    }
    
    // Extract a count (or return 1) and increment the index
    auto extractCount(const string& formula, int& i) {
        int count = 0;
        while (i < formula.size() && isdigit(formula[i])) {
            count = count * 10 + formula[i++] - '0';
        }
        
        return count == 0 ? 1 : count;
    }
    
    void multiplyBlock(vector<Token>& st, int count) {
        vector<Token> block;
        while (st.back().name != "(") {
            block.push_back(st.back());
            st.pop_back();
        }
        st.pop_back(); // Remove the "("

        // Multiply block by count and put it back on the stack
        for (auto& token: block) {
            token.val *= count;
            st.push_back(token);
        }
    }
    
    auto generateResult(vector<Token>& st) {    
        // Generate result. Merge repeating tokens and sort
        unordered_map<string, int> counts;
        for (auto& token: st) {
            counts[token.name] += token.val;
        }
        
        vector<pair<string, int>> vec(begin(counts), end(counts));
        sort(begin(vec), end(vec), [](auto& a, auto& b) {
            return a.first < b.first;
        });
        
        string res;
        for (auto& p: vec) {
            res += p.first;
            if (p.second > 1) {
                res += to_string(p.second);
            }
        }
        
        return res;
    }
    
public:
    // Time: O(n), Space: O(n)
    string countOfAtoms(string formula) {
        vector<Token> st;
        
        int i = 0;
        
        for (; i < formula.size();) {
            // Beginning of element found
            if (isupper(formula[i])) {
                auto name = extractName(formula, i);
                auto count = extractCount(formula, i);                
                st.push_back({name, count});
            } 
            // Handle opening
            else if (formula[i] == '(') {
                st.push_back({"(", 0});
                ++i;
            }
            // Handle closing
            else if (formula[i] == ')') {
                ++i; // Skip ")"
                auto count = extractCount(formula, i);
                multiplyBlock(st, count);
            }
        }
                
        return generateResult(st);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}