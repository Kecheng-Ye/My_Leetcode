#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Intuition:
    //     1. Start with a clean graph that assume every vertices is separate to each other
    //     2. From ascending order of vertices value, try to group those vertices with valid neighbor (has value <= to the target vertex) with union find
    //     3. Use the Union find's functionality to check if any group has contain more than one target vertex
    //     4. If so we are pretty sure there exist some path between any combination of those vertices
    //     5. Given a group contains target vertices [a, b, c], the possible combination is 2C3 = (3 * (3 - 1))/ 2!
    //     6. Go back to step 2 until all nodes has been exhausted
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int n = vals.size();
        vector<vector<int>> graph(n);
        unordered_map<int, vector<int>> valToNode;

        // E
        for (const auto& edge : edges) {
            if (vals[edge[0]] >= vals[edge[1]]) {
                graph[edge[0]].push_back(edge[1]);
            }

            if (vals[edge[0]] <= vals[edge[1]]) {
                graph[edge[1]].push_back(edge[0]);
            }
        }

        // V
        for (int i = 0; i < n; i++) {
            valToNode[vals[i]].push_back(i);
        }

        UnionFind uf(n);

        // VlogV
        set<int> valSet(vals.begin(), vals.end());
        int result = n;

        // V + E
        for (const int value : valSet) {
            // parents -> num of node
            unordered_map<int, int> parentsToCurNode;

            for (const int node : valToNode[value]) {
                for (const int neighbor : graph[node]) {
                    uf.Union(node, neighbor);
                }
                parentsToCurNode[uf.findParent(node)] += 1;
            }

            for (const auto& [_, numOfNode] : parentsToCurNode) {
                result += (numOfNode * (numOfNode - 1)) / 2;
            }
        }

        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int size): parents(size), rank(size) {
            for (int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }

        bool Union(const int a, const int b) {
            const int parentA = findParent(a);
            const int parentB = findParent(b);

            if (parentA == parentB) {
                return false;
            }

            if (rank[parentA] == rank[parentB]) {
                parents[parentB] = parentA;
                rank[parentA] += 1;
            } else if (rank[parentA] > rank[parentB]) {
                parents[parentB] = parentA;
            } else {
                parents[parentA] = parentB;
            }

            return true;
        }

        int findParent(const int i) {
            if (parents[i] != i) {
                parents[i] = findParent(parents[i]);
            }
            return parents[i];
        }

    private:
        vector<int> parents;
        vector<int> rank;
    };
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}