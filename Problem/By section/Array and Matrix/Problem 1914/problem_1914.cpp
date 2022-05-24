#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<int> vec;
        int n = grid.size(),m = grid[0].size();
        for(int i = 0;i<min(n,m)/2;i++){
            //Copy All Border Elements in vector
            
            //First Row
            for(int j = i;j<m-i;j++){
                vec.push_back(grid[i][j]);
            }
            //Second Column
            for(int j = i+1;j<n-i-1;j++){
                vec.push_back(grid[j][m-i-1]);
            }
            //Last Row
            for(int j = m-i-1;j>=i;j--){
                vec.push_back(grid[n-i-1][j]);
            }
            //First Column
            for(int j = n-i-2;j>=i+1;j--){
                vec.push_back(grid[j][i]);
            }
            
            //Rotate Vector by k
            reverse(vec.begin(),vec.end());
            reverse(vec.begin(),vec.begin()+vec.size()-k%vec.size());
            reverse(vec.begin()+vec.size()-k%vec.size(),vec.end());

            
            //Reasign Rotated Vector to grid
            int l = 0;
            
            //First Row
            for(int j = i;j<m-i;j++){
                grid[i][j] = vec[l];
                l++;
            }
            //Second Column
            for(int j = i+1;j<n-i-1;j++){
                grid[j][m-i-1] = vec[l];
                l++;
            }
            //Last Row
            for(int j = m-i-1;j>=i;j--){
                grid[n-i-1][j] = vec[l];
                l++;
            }
            //First Column
            for(int j = n-i-2;j>=i+1;j--){
                grid[j][i] = vec[l];
                l++;
            }
            vec.clear();
        }
        return grid;
    }
    
    void print_arr(vector<int>& arr) {
        for(const int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}