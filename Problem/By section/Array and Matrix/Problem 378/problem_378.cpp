#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
//     // Time: O(k + klog(k)), Space: O(k)
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         priority_queue<node, vector<node>, function<bool(const node&, const node&)>> pq(is_bigger);

//         for(int i = 0; i < min(n, k); i++) {
//             pq.push(node(matrix[i][0], i, 0));
//         }

//         while(k-- > 1) { // only need k - 1 pop
//             node temp = pq.top();
//             pq.pop();

//             if(temp.col < n - 1) {
//                 pq.push(node(matrix[temp.row][temp.col + 1], temp.row, temp.col + 1));
//             }
//         }

//         return pq.top().val;
//     }

// private:
//     struct node{
//         int val;
//         int row;
//         int col;

//         node(int val, int row, int col) :val(val), row(row), col(col) {}
//     };

//     static bool is_bigger(const node& a, const node& b) {
//         return a.val > b.val;
//     }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n && matrix[i][j] < mid; j++) {
                    cnt++;
                }
            }
            if (cnt < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    vector<vector<int>> test = {{1,5,9},{10,11,13},{12,13,15}};
    s.kthSmallest(test, 5);


    return 0;
}