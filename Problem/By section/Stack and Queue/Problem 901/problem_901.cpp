#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
    }
    
    // Time: O(1), Space: O(1)
    int next(int price) {
        int single_result = 1;
        while(!s.empty() && price >= s.top().first) {
            single_result += s.top().second;
            s.pop();
        }
        s.push({price, single_result});
        return single_result;
    }
private:
    stack<pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}