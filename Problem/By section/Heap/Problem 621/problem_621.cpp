#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn) Space: O(n)
    int leastInterval(vector<char>& tasks, int n) {
        const int size = tasks.size();
        
        unordered_map<int, int> taskReadyToBeSchduled;
        queue<pair<int, int>> bufferList;   // [time, rest]
        priority_queue<int, vector<int>> nextschedule;  // [num of task] 

        for (const auto& task : tasks) {
            taskReadyToBeSchduled[task] += 1;
        }

        for (const auto& [unique_task, freq] : taskReadyToBeSchduled) {
            nextschedule.push(freq);
        }

        int currInteval = 0;
        while (!nextschedule.empty() || !bufferList.empty()) {
            if (!nextschedule.empty()) {
                const auto nextAvl = nextschedule.top(); nextschedule.pop();

                if (nextAvl - 1 > 0)
                    bufferList.push({currInteval + n ,nextAvl - 1});
            }

            if (!bufferList.empty()) {
                const auto [nextTime, rest] = bufferList.front();
                if (nextTime == currInteval) {
                    bufferList.pop();
                    nextschedule.push(rest);
                }
            }

            currInteval++;
        }

        return currInteval;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}