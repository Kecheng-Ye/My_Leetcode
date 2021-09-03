#include <bits/stdc++.h>

using namespace std;

void print_queue(queue<pair<int, int>> queue) {
    while(!queue.empty()) {
        auto it = queue.front();
        queue.pop();

        cout << "[" << it.first << ", " << it.second << "] ";
    }

    cout << endl;
}

class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool check_valid(int x, int y, int n) {
        if(x < 0 || y < 0 || x >= n || y >= n) {
            return false;
        }else {
            return true;
        }
    }

public:
    // Time: O(n^2), Space: O(n^2)
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0 || grid[0][0] || grid[n - 1][n - 1]) return -1;

        queue<pair<int, int>> queue;
        int result = 0;

        queue.push(make_pair(0, 0));
        grid[0][0] = 2;

        while(!queue.empty()) {
            int this_layer = queue.size();

            while(this_layer) {
                auto temp = queue.front();
                queue.pop();
                int curr_x = temp.first;
                int curr_y = temp.second;

                if(curr_x == n - 1 && curr_y == n - 1) {
                    return result + 1;
                }else{
                    for(const auto& direction : directions) {
                        int new_x = curr_x + direction[0];
                        int new_y = curr_y + direction[1];

                        if(check_valid(new_x, new_y, n) && grid[new_x][new_y] == 0) {
                            grid[new_x][new_y] = 2;
                            queue.push(make_pair(new_x, new_y));
                        }
                    }
                }

                this_layer--;
            }

            result++;
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> matrix = {{0,0,0},{1,1,0},{1,1,0}};
    cout << s.shortestPathBinaryMatrix(matrix) << endl;
    return 0;
}