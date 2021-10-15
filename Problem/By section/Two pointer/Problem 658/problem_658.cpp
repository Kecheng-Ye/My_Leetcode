#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {  
        int n = arr.size();
        if(k >= n) return arr;
        
        int left = 0, right = n - 1;
        
        while(left <= right & right - left + 1 > k) {
            int diff_1 = abs(arr[left] - x);
            int diff_2 = abs(arr[right] - x);
            if(diff_1 > diff_2) {
                left++;
            }else if(diff_2 > diff_1) {
                right--;
            }else{
                right--;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}