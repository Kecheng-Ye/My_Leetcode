#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();      
        if(k >= n) return 0;
       
       unordered_map<int, int> record;
       
       for(const auto& num : arr) {
         record[num]++;
       }
                         // num, occurance of num
       priority_queue<pair<int, int>, vector<pair<int, int>>, 
                function<bool(const pair<int, int>&, const pair<int, int>&)>> q(compare);
       
       for(const auto& p : record) {
         q.push(p);
       }
       
       while(k) {
         auto number = q.top();
         
         if(k < number.second) break;
         k -= number.second;
         q.pop();
       }
       
       return q.size();
    }
    
private:
  static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}