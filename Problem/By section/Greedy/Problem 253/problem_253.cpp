#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    // Time: O(nlogn), Space: O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<int> cur_rooms;
        
        for(const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            bool check_room = false;
            
            for(auto& room : cur_rooms) {
                if(start >= room) {
                    check_room = true;
                    room = end;
                    break;
                }
            }
            
            if(!check_room) {
                cur_rooms.push_back(end);
            }
        }
        
        return cur_rooms.size();
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}