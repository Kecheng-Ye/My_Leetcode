#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<bool> on_path;
    bool find_cycle;
    
    // Time: O(E + V), Space: O(1)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        on_path = vector<bool>(numCourses, false);
        find_cycle = false;
        vector<vector<int>> graph = build_graph(numCourses, prerequisites);
        
        
        for(int i = 0; i < numCourses; i++) {
            traverse(graph, i);
            if(find_cycle) return false;
        }
        
        return true;
    }
    
    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> result(numCourses, vector<int>());
        
        for(auto& pair : prerequisites) {
            result[pair[1]].push_back(pair[0]);
        }
        
        return result;
    }
    
    void traverse(vector<vector<int>>& prerequisites, int start) {
        if(on_path[start]) { // find a loop
            find_cycle = true;
            return;
        }
        
        if(visited[start]) { // reached to a previous traversed point
            return;          // this is not necessarily a loop because we are in a directed graph
        }                   
        
        visited[start] = true; // one traversed never traversed again
        on_path[start] = true; // we are on a search path starting at start
        
        for(int neighbour : prerequisites[start]) {
            traverse(prerequisites, neighbour);
            if(find_cycle) return;
        }
        
        on_path[start] = false; // once we finish this traverse, we backtrack back
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}