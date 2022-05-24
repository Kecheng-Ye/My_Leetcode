#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //  Steps:
    //      1. Add all values of current row with all values of next row.
    //      2. Sort the row.
    //      3. Take first k elements and Remove the rest.
    //  Do until you have added all rows. Return (k-1) the element.
    //  Why it is working?

    //  Lets take an example,
    //      1 10 10
    //      1  4  5
    //      2  3  6

    //  If we add all values of 1st row and 2nd row,
    //  we get 1+1, 1+4, 1+5, 10+1, 10+4, 10+5, 10+1, 10+4, 10+5.
    //  After sort, 1+1, 1+4, 1+5, 10+1, 10+1, 10+4, 10+4, 10+5, 10+5.
    //  Now, if k = 5, we can take only first 5 elements of the array because kth sum can not be gotten from the rest. After pruning, 1+1, 1+4, 1+5, 10+1, 10+1.

    //  In the same way, we will add 3rd, 4th, ... ,mth row.

    // Time: O(mnk + mnklognk), Space: O(nk)
    void find(vector<vector<int>>& mat, int index, int k, vector<int>& sums) {
        if(index >= mat.size()) return;
        
        vector<int> new_sums;
        for(int i=0;i<sums.size();i++) {
            for(int j=0;j<mat[index].size();j++) {
                new_sums.push_back(sums[i] + mat[index][j]);
            }
        }
        
        sort(new_sums.begin(), new_sums.end());
        
        while(new_sums.size() > k) new_sums.pop_back();
        
        sums = new_sums;
        
        find(mat, index+1, k, sums);
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];
        
        find(mat, 1, k, sums);
        
        return sums[k-1];
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}