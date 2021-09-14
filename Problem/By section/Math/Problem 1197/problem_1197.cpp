#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> directions = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    
    int minKnightMoves(int x, int y) {
        // We work from the target location back to the origin (knight moves are reversible)
        // base case, we are at the origin
        if (x == 0 and y == 0) return 0;  
        // observe: Solutions are symmetrical. No matter which quadrant of the coordinate system we are in,
        // the steps to get there are the same amount
        if (x < 0 or y < 0) return minKnightMoves(abs(x), abs(y));
        // observe: The steps to get to (x,y) are the same amount as to get to (y,x)
        if (y > x) return minKnightMoves(y,x);
        // Now observe: in all but 4 of the remaining cases, the optimal jump is left 2 down 1
        // Here, we must go two left and 1 UP
        if (x == 3 and y == 1) return 1 + minKnightMoves(x-2,y+1);
        if (x == 4 and y == 3) return 1 + minKnightMoves(x-2,y+1);
        if (x == 1 and y == 1) return 1 + minKnightMoves(x-2,y+1);
        // Here, we must go two UP and 1 RIGHT
        if (x == 2 and y == 0) return 1 + minKnightMoves(x-1,y+2);
        return 1+minKnightMoves(x-2, y-1);
    }
    
    
//     int minKnightMoves(int x, int y) {
//         if(x == 0 && y == 0) return 0;
        
//         return Bidirectional_BFS(x, y);
//     }
    
//     int Bidirectional_BFS(int x, int y) {
//         queue<vector<int>> queue_from_origin;
//         unordered_map<string, int> distance_from_origin;
//         queue_from_origin.push({0, 0, 0});
//         distance_from_origin["0,0"] = 0;
        
//         queue<vector<int>> queue_from_target;
//         unordered_map<string, int> distance_from_target;
//         queue_from_target.push({x, y, 0});
//         distance_from_target[to_string(x) + "," + to_string(y)] = 0;
        
//         while(true) {
//             auto new_from_origin = queue_from_origin.front();
//             queue_from_origin.pop();
//             string new_from_origin_str = to_string(new_from_origin[0]) + "," + to_string(new_from_origin[1]);
            
            
//             if(distance_from_target.count(new_from_origin_str)) 
//                 return distance_from_target[new_from_origin_str] + new_from_origin[2];
            
//             auto new_from_target = queue_from_target.front();
//             queue_from_target.pop();
//             string new_from_target_str = to_string(new_from_target[0]) + "," + to_string(new_from_target[1]);
            
//             if(distance_from_origin.count(new_from_target_str)) 
//                 return distance_from_origin[new_from_target_str] + new_from_target[2];
            
            
//             for(auto direction : directions) {
//                 vector<int> new_point_origin = {new_from_origin[0] + direction[0], new_from_origin[1] + direction[1], new_from_origin[2] + 1};
//                 string new_point_origin_str = to_string(new_point_origin[0]) + "," + to_string(new_point_origin[1]);
                
                
//                 if(!distance_from_origin.count(new_point_origin_str)) {
//                     distance_from_origin[new_point_origin_str] = new_point_origin[2];
//                     queue_from_origin.push(new_point_origin);
//                 }
                
//                 vector<int> new_point_target = {new_from_target[0] + direction[0], new_from_target[1] + direction[1], new_from_target[2] + 1};
//                 string new_point_target_str = to_string(new_point_target[0]) + "," + to_string(new_point_target[1]);
                   
                   
//                 if(!distance_from_target.count(new_point_target_str)) {
//                     distance_from_target[new_point_target_str] = new_point_target[2];
//                     queue_from_target.push(new_point_target);
//                 }
//             }
//         }
        
//         return -1;
//     }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}