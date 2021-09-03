#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = INT_MIN;
        int min = INT_MAX;

        for(auto i : prices) {
            if(i < min) {
                min = i;
            }else{
                // important!!! 
                // if one value is min there that day cannot be the most profitable day
                result = max(result, min - i);
            }
        }

        return result;
    }
};