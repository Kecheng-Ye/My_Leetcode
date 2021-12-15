#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> lexicalOrder(int n) {
        vector<int> result(1, 1);
        
        while(result.size() < n) {
            int back = result.back();
            if(back * 10 <= n) {
                result.push_back(back * 10);
            }else{
                while(back + 1 > n || (back + 1) % 10 == 0 ) {
                    back /= 10;
                }
                
                result.push_back(back + 1);
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}