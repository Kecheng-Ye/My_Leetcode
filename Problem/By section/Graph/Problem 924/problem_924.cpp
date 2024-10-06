#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(V + E), Space: O(V)
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initials) {
        sort(initials.begin(), initials.end());
        const int n = graph.size();

        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && graph[i][j] == 1) {
                    uf.Union(i, j);
                }
            }
        }

        // component number -> component size
        unordered_map<int, int> connectedComponentSize;
        for (int i = 0; i < n; i++) {
            connectedComponentSize[uf.parents[i]] += 1;
        }

        // component number -> [initalize that is inside the component]
        unordered_map<int, vector<int>> connectedComponentInitiali;
        for (const int initial : initials) {
            connectedComponentInitiali[uf.parents[initial]].push_back(initial);
        }
        
        int result = INT_MAX;
        int currMax = 0;

        for (const auto& [group, _initials] : connectedComponentInitiali) {
            if (_initials.size() == 1 && connectedComponentSize[group] >= currMax) {
                result = min(result, _initials.front());
                currMax = max(currMax, connectedComponentSize[group]);
            }
        }

        return (result == INT_MAX) ? initials.front() : result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int size): parents(size), ranks(size, 1) {
            for (int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }

        bool Union(const int x, const int y) {
            const int parentX = findParent(x);
            const int parentY = findParent(y);

            if (parentX == parentY) {
                return false;
            }

            if (ranks[parentX] == ranks[parentY]) {
                parents[parentY] = parentX;
                ranks[parentX] += 1;
            } else if (ranks[parentX] > ranks[parentY]) {
                parents[parentY] = parentX;
            } else {
                parents[parentX] = parentY;
            }
            return true;
        }

        vector<int> parents;
    private:
        int findParent(const int i) {
            if (parents[i] != i) {
                parents[i] = findParent(parents[i]);
            }
            return parents[i];
        }

        vector<int> ranks;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}