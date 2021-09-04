#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<bool> on_path;
    bool find_cycle;
    vector<int> post_order;
    
    // Time: O(E + V), Space: O(V)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        on_path = vector<bool>(numCourses, false);
        post_order = vector<int>();
        find_cycle = false;
        vector<vector<int>> graph = build_graph(numCourses, prerequisites);
        
        
        for(int i = 0; i < numCourses; i++) {
            traverse(graph, i);
            if(find_cycle) return {};
        }
        
        
        reverse(post_order.begin(), post_order.end());
        return post_order;
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
        post_order.push_back(start);
        
    }
    
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}