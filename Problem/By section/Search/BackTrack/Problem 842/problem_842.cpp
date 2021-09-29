#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(10 * 10 * n), Space: O(n)
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        backtrack(result, num, 0, -1, -1);
        return result;
    }
    
    bool backtrack(vector<int>& result, string num_str, int cur_idx, long long prev_2, long long prev_1) {
        if(result.size() >= 3 && cur_idx == num_str.size()) {
            return true;
        }else{
            long long num = 0;
            int len = num_str[cur_idx] == '0' ? 1 : 10;
            for(int i = cur_idx; i < min(cur_idx + len, (int)num_str.size()); i++) {
                num = num * 10 + (num_str[i] - '0');
                
                if(num > INT_MAX) break;
                
                result.push_back(num);
                
                if(prev_2 == -1) {
                    if(backtrack(result, num_str, i + 1, num, prev_1)) return true;
                }else if(prev_1 == -1) {
                    if(backtrack(result, num_str, i + 1, prev_2, num)) return true;
                }else{
                    if(num == prev_1 + prev_2) {
                        if(backtrack(result, num_str, i + 1, prev_1, num))
                            return true;
                    }else if(num > prev_1 + prev_2) { //pruning here
                        result.pop_back();
                        break;
                    }else if(num < prev_1 + prev_2) { 
                        
                    }
                }
                
                result.pop_back();
            }
        }
        
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}