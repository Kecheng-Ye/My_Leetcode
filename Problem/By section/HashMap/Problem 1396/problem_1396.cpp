#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {
public:
    // s = the number of stations on the network
    // p = the number of passengers making a journey concurrently during peak time
    // Space: O(s^2 + p)
    UndergroundSystem() {

    }

    // Time: O(1)
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }

    // Time: O(1)
    void checkOut(int id, string stationName, int t) {
        const auto& [checkInStation, checkInTime] = checkInMap[id];
        const string key = checkInStation + '-' + stationName;
        const int duration = t - checkInTime;

        if (!avgTimeMap.count(key)) {
            avgTimeMap[key] = {(double)duration, 1};
        } else{
            const auto& [curAvgTime, count] = avgTimeMap[key];
            const double newAvgTime = ((curAvgTime * count) + (double) (duration)) / (count + 1);
            avgTimeMap[key] = {newAvgTime, count + 1};
        }
    }

    // Time: O(1)
    double getAverageTime(string startStation, string endStation) {
        const string key = startStation + '-' + endStation;
        return avgTimeMap[key].first;
    }

private:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<double, int>> avgTimeMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, char** argv) {
    return 0;
}
