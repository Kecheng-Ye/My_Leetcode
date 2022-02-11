#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return (pow(a[0], 2) + pow(a[1], 2)) < (pow(b[0], 2) + pow(b[1], 2));
    }
    
    // Time: O(nlogk), Space: O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if(k == n) return points;
        
        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> q(compare); // cannot use decltyoe(func) if func is not a lambda
        
        for(const auto& point : points) {
            q.push(point);
            if(q.size() > k) {
                q.pop();
            }
        }
        
        vector<vector<int>> result;
        
        while(!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}