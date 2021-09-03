#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool perfect_square(int n) {
        int limit = sqrt(n);
        if(limit * limit == n) return true;

        return false;
    }

public:
    // Time: O(n), Space: O(sqrt(n)^sqrt(n))
    int numSquares(int n) {
        if(perfect_square(n)) return 1;

        queue<int> q;
        int result = 1;
        bool record[n + 1];
        
        // should initialize array number for C++ 
        for(auto& i : record) {
            i = false;
        }

        q.push(n);

        while(!q.empty()) {
            int this_layer = q.size();

            while(this_layer) {
                auto temp = q.front();
                q.pop();

                if(perfect_square(temp)) {
                    return result;
                }

                for(int i = 1; i <= (int)sqrt(temp); i++) {
                    int left = temp - pow(i, 2);
                    
                    // branch pruning
                    if(left < 0) break;

                    if(record[left]) continue;

                    q.push(left);
                    record[left] = true;
                }

                this_layer--;
            }

            result++;
        } 

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numSquares(12) << endl;
    
    // bool test[100];

    // cout << test[0] << " " << test[99] << endl;
    
    return 0;
}