#include <bits/stdc++.h>

using namespace std;

class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        vec = vector<int>(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++) {
            if(vec[i]) valid.insert(i);
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& v) {
        int result = 0;
        
        for(const int pos : valid) {
            if(v.valid.count(pos)) result += v[pos] * vec[pos];
        }
        
        return result;
    }
    
    int operator[](const int& i) {
        return vec[i];
    }
    
    unordered_set<int> valid;
    vector<int> vec;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}