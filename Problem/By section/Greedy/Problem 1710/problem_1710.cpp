#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1]; 
    }   
    
    // Time: O(nlogn), Space: O(n)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int result = 0;
        
        for(const auto& box : boxTypes) {
            if(box[0] <= truckSize) {
                result += box[0] * box[1];
                truckSize -= box[0];
            }else{
                result += truckSize * box[1];
                break;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}