#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // struct node {
    //     int val;
    //     int postion;
    // };

    // static bool compare(const node& a, const node& b) {
    //     if(a.val == b.val) return a.postion > b.postion;
        
    //     return a.val < b.val;
    // }
    
    // Time: O(nlogn), Space: O(n)
    // int maximumSwap(int num) {
    //     if(!(num / 10)) 
    //         return num;
        
    //     int decimal = 0;
    //     priority_queue<node, vector<node>, function<bool(const node&, const node&)>> pq(compare);
        
    //     int temp = num;
        
    //     while(temp) {
    //         int cur_decimal = temp % 10;
    //         pq.push({cur_decimal, decimal++});
    //         temp /= 10;
    //     }
        
    //     temp = num;
        
    //     for(int i = decimal - 1; i >= 0; i--) {
    //         int front_val = temp / pow(10, i);
            
    //         while(!pq.empty() && pq.top().postion >= i) {
    //             pq.pop();
    //         }
            
    //         auto candidate = pq.top();
            
    //         if(front_val < candidate.val) {
    //             num += (candidate.val - front_val) * pow(10, i);
    //             num -= (candidate.val - front_val) * pow(10, candidate.postion);
    //             break;
    //         }
            
    //         temp -= front_val * pow(10, i);
    //     }
        
    //     return num;
    // }
    
    // Time: O(n), Space: O(n)
    int maximumSwap(int num) {
        auto arr = to_string(num);
        vector<vector<int>> store(2, vector<int>(arr.size()));
        int max = arr.back() - '0';
        int index = arr.size() - 1;
        store[0][arr.size() - 1] = max;
        store[1][arr.size() - 1] = index;
        
        // use a matrix to represent the cur max from num[i, end]
        for (int i = arr.size() - 2; i >= 0; i --) {
            if (arr[i] - '0' > max) {
                max = arr[i] - '0';
                index = i;
            }
            store[0][i] = max;
            store[1][i] = index;
        }
        
        // do one time swap if we see a digit that is not the current max
        for (int i = 0; i < arr.size(); i ++) {
            if (store[0][i] > (arr[i] - '0')) {
                char temp = arr[i];
                arr[i] =  arr[store[1][i]];
                arr[store[1][i]] = temp;
                return stoi(arr);
            }
        }
        return num;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}