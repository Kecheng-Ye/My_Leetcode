#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, k = 0;
        int answer = 0;
        while(j < g.size() && k < s.size()) {
            if(g[j] <= s[k]) {
                answer++;
                j++;
                k++;
            }else{
                k++;
            }
        }

        return answer;
    }
};

int main(int argc, char** argv) {
    return 0;
}