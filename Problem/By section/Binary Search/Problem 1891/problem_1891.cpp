#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int maxLength(vector<int>& ribbons, int k) {
        int n = ribbons.size();
        if(n == 1) return ribbons[0] / k;
        
        int i = 1;
        int j = *max_element(ribbons.begin(), ribbons.end()) + 1;
        
        while(i < j) {
            int mid = i + (j - i) / 2;
            int try_cut = single_test(ribbons, mid);
            
            if(try_cut >= k) {
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        
        return i - 1;
    }
    
    int single_test(vector<int>& ribbons, int cut) {
        int result = 0;
        
        for(const auto& ele : ribbons) {
            result += (ele / cut);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}