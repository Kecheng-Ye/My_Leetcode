#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, string>> ref = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, 
        {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"},
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},
        {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, 
        {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, 
        {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"} 
    };

    // O(logn), Space: O(1)
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        for (const auto& [val, repr] : ref) {
            if (num >= val) {
                string result;

                // after 100, the (divider * val repr + remainder) logic is valid
                if (num >= 100) result += (numberToWords((num / val)) + " ");
                
                // if it is within 100, we directly use repr + remainder
                result += repr;
                if (num % val != 0) {
                    result += " ";
                    result += numberToWords((num % val));
                }
                return result;
            }
        }

        return "";
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}