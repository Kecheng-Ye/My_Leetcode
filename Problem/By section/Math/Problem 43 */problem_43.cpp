#include <bits/stdc++.h>

using namespace std;

// #define charToNum(c) ((int)(c - '0'))
// #define digitToChar(d) ((char)(d + '0'))

// class Solution {
// public:
//     Time: O((n * m) * (m + n)), Space: O(m + n) 
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0") {
//             return "0";
//         }

//         const int m = num1.size(), n = num2.size();
//         string result;

        
//         for (int j = n - 1; j >= 0; j--) {
//             int carry = 0;
//             string singleProduct;
//             int i = m - 1;
//             while (i >= 0 || carry > 0) {
//                 if (i >= 0) {
//                     carry += charToNum(num1[i--]) * charToNum(num2[j]);
//                 }

//                 singleProduct = digitToChar(carry % 10) + singleProduct;
//                 carry /= 10;
//             }

//             result = add(result, singleProduct + string(n - 1 - j, '0'));
//         }

//         return result;
//     }

//     string add(string num1, string num2) {
//         const int m = num1.size(), n = num2.size();
//         int i = m - 1, j = n - 1;
//         int carry = 0;

//         string result;
//         while (i >= 0 || j >= 0 || carry > 0) {
//             if (i >= 0) {
//                 carry += charToNum(num1[i--]);
//             }

//             if (j >= 0) {
//                 carry += charToNum(num2[j--]);
//             }

//             result = digitToChar(carry % 10) + result;
//             carry /= 10;
//         }

//         return result;
//     }   
// };

class Solution {
public:
    // Time: O(n * m), Space: O(m + n)
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> pos(m + n);
   
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); 
                int p1 = i + j;     // tens digit position
                int p2 = i + j + 1; // ones digit position
                int sum = mul + pos[p2];  // add the current mul to the current ones digit result
                                          // util here the value pos[p2] will be confirmed
                pos[p1] += sum / 10;
                pos[p2] = (sum) % 10;
            }
        }  
        
        string sb;
        for(int p : pos) if(!(sb.size() == 0 && p == 0)) { sb += to_string(p);}
        return sb.size() == 0 ? "0" : sb;
    }   
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}