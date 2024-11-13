#include <bits/stdc++.h>

using namespace std;

#define LIMIT 300

// class HitCounter {
// public:
//     HitCounter(): clicksSum(), aggregationSum(0) {
        
//     }
    
//     void hit(int timestamp) {
//         clicksSum.push_back(
//             {
//                 (aggregationSum += 1),
//                 timestamp
//             }
//         );
//     }
    
//     int getHits(int timestamp) {
//         const int targetStart = max(0, timestamp - LIMIT);
//         const int startIdx = searchLeftBound(targetStart);
//         const int startClick = (startIdx == -1) ? 0 : clicksSum[startIdx].first;

//         return aggregationSum - startClick;
//     }

// private:
//     int searchLeftBound(const int targetTimeStamp) {
//         int i = 0, j = clicksSum.size();

//         while (i < j) {
//             const int mid = i + (j - i) / 2;
//             const int currTime = clicksSum[mid].second;

//             if (currTime == targetTimeStamp) {
//                 i = mid + 1;
//             } else if (currTime > targetTimeStamp) {
//                 j = mid;
//             } else {
//                 i = mid + 1;
//             }
//         }

//         return i - 1;
//     }

//     vector<pair<int, int>> clicksSum;
//     int aggregationSum;
// };

class HitCounter {
public:
    HitCounter(): clicksSum(), aggregationSum(0) {
        
    }
    
    void hit(int timestamp) {
        if (!clicksSum.empty() && clicksSum.back().second == timestamp) {
            clicksSum.back().first += 1;
        } else {
            clicksSum.push_back(
                {
                    1,
                    timestamp
                }
            );
        }

        aggregationSum += 1;
    }
    
    int getHits(int timestamp) {
        const int targetStart = max(0, timestamp - LIMIT);
        while (!clicksSum.empty() && clicksSum.front().second <= targetStart) {
            aggregationSum -= clicksSum.front().first;
            clicksSum.pop_front();
        }

        return aggregationSum;
    }

private:
    deque<pair<int, int>> clicksSum;
    int aggregationSum;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

int main(int argc, char** argv) {    
    return 0;
}