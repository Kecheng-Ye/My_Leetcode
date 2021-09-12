#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if(n == 1) return 0;
        
        priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
        int result = 0;
        
        while(q.size() > 1) {
            int smallest = q.top();
            q.pop();
            int sec_smallest = q.top();
            q.pop();
            
            int sum = smallest + sec_smallest;
            result += sum;
            q.push(sum);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}