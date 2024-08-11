#include <bits/stdc++.h>

using namespace std;

#define left(x, y, n) (((x) * n + (y)) * 4 + 0)
#define top(x, y, n) (((x) * n + (y)) * 4 + 1)
#define right(x, y, n) (((x) * n + (y)) * 4 + 2)
#define bottom(x, y, n) (((x) * n + (y)) * 4 + 3)

class Solution {
public:
    // Time: O(4mn), Space: O(4mn)
    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        UnionFind uf(n * n * 4);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    uf._union(top(i, j, n), bottom(i - 1, j, n));
                } 

                if (j > 0) {
                    uf._union(left(i, j, n), right(i, j - 1, n));
                }

                if (grid[i][j] != '/') {
                    uf._union(top(i, j, n), right(i, j, n));
                    uf._union(left(i, j, n), bottom(i, j, n));
                }

                if (grid[i][j] != '\\') {
                    uf._union(top(i, j, n), left(i, j, n));
                    uf._union(right(i, j, n), bottom(i, j, n));
                }
            }
        }

        return uf.groups;
    }

private:
    class UnionFind {
    public:
        int groups;

        UnionFind(const int n): parents(n), ranks(n, 0), groups(n) {
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
        }

        bool _union(const int i, const int j) {
            const int parentI = findParents(i), parentJ = findParents(j);
            
            if (parentI == parentJ) {
                return false;
            }

            if (ranks[parentI] == ranks[parentJ]) {
                ranks[parentI]++;
                parents[parentJ] = parentI;
            } else if (ranks[parentI] > ranks[parentJ]) {
                parents[parentJ] = parentI;
            } else {
                parents[parentI] = parentJ;
            }

            groups--;
            return true;
        }

    private:
        int findParents(int i) {
            if(i != parents[i]) {
                parents[i] = findParents(parents[i]);
            }
            
            return parents[i];
        }

        vector<int> parents;
        vector<int> ranks;
    };
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> grid = {"/\\","\\/"};
    cout << s.regionsBySlashes(grid);
    return 0;
}