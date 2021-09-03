#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    // Time: O(n), Space: O(len(a))
    bool circular_contain(string a, string b) {
        string double_a = a + a;
        return double_a.find(b) != string::npos;
    }


};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}