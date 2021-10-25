#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node{
        int val;
        int freq;
        int presum;
        
        node(int v, int f, int p): val(v), freq(f), presum(p) {};
    };
    
    const int limit = 1e9 + 7;
    
    // Time: O(n), Space: O(n)
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        
        stack<node> s;
        s.push(node(arr[0], 1, 0));
        int idx = 0;
        int result = arr[0];
        
        while(++idx < n) {
            int temp = 1;
            while(!s.empty() && s.top().val >= arr[idx]) {
                temp += s.top().freq;
                s.pop();
            }
            
            int previous = (s.empty()) ? 0 : (s.top().presum) + s.top().freq * s.top().val;
            result += previous + arr[idx] * temp;
            s.push(node(arr[idx], temp, previous));
            if(result >= limit) result %= limit;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}