#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // static bool compare(const vector<int>& a, const vector<int>& b) {
//     //     return a[0] > b[0];
//     // }
    
//     int brightestPosition(vector<vector<int>>& lights) {
//         int n = lights.size();
//         int _min = INT_MAX;
//         int _max = INT_MIN;
        
//         vector<vector<int>> intervals(n);
//         int count = 0;
//         for(const auto& light : lights) {
//             int left = light[0] - light[1];
//             _min = min(_min, left);
            
//             int right = light[0] + light[1];
//             _max = max(_max, right);
//             intervals[count++] = {left, right};
//         }
        
//         int size = _max - _min + 1;
//         vector<int> result(size);
        
//         for(const auto& interval : intervals) {
//             int left = interval[0], right = interval[1];
            
//             result[left - _min] += 1;
//             if(right - _min + 1 < size) result[right - _min + 1] -= 1;
//         }
        
//         int idx = 0;
//         int max_light = result[0];
        
//         for(int i = 1; i < size; i++) {
//             result[i] += result[i - 1];
            
//             if(result[i] > max_light) {
//                 max_light = result[i];
//                 idx = i;
//             }
//         }
        
//         return idx + _min;
//     }
// };

class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        // Sweep Line algorithm
        std::map<int,int>map;
        for(int i=0;i<(int)lights.size();i++){
            int start = lights[i][0]-lights[i][1];
			// Based on the question, 
			// there is light radiation contribution at point (center + radius)
			// Therefore, the end point is lights[i][0] + lights[i][1]+1.
            int end = lights[i][0] + lights[i][1]+1;
            map[start]+= 1;
            map[end] -= 1;
        }
        int sum = INT_MIN;
        int max_val = INT_MIN;
        int result = INT_MIN;
        
        // the maximum with smallest index will definitely appear at 
        // the start of some range
        // so we don't need a whole array to check each point one by one
        // only check start and end point of one interval
        for(auto it = map.begin();it!=map.end();it++){
            if(sum == INT_MIN) sum = it->second;
            else sum += it->second;
            if(sum > max_val){
                max_val = sum;
                result = it->first;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}