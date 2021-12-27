#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    string reorganizeString(string s) {
        unordered_map<char, int> record;
        int _max = INT_MIN;
        
        for(const auto c : s) {
            record[c]++;
            _max = max(_max, record[c]);
        }
        
        if(_max > (s.size() + 1) / 2) return "";
        
        priority_queue<node, vector<node>, function<bool(const node&, const node&)>> pq(compare);
        
        for(auto [c, freq] : record) {
            pq.push({c, freq});
        }
        
        string result = "";
        
        // since we are extracting two elements at one time
        // we should not expect that every time pq's size will decrement to extactly 0
        while(pq.size() > 1) {
            auto [c1, freq1] = pq.top();
            pq.pop();
            
            auto [c2, freq2] = pq.top();
            pq.pop();
            
            // Greedy here!!!!
            // we add the top 2 frequent char to the result string
            result += c1;
            result += c2;
            
            if(freq1 > 1) pq.push({c1, freq1 - 1});
            if(freq2 > 1) pq.push({c2, freq2 - 1});
        }
        
        // check the last one char 
        if(!pq.empty()) {
            auto [c, freq] = pq.top();
            result += c; 
        }
        
        return result;
    }
    
private:
    struct node {
        char c;
        int freq;
    };
    
    static bool compare(const node& a, const node& b) {
        return a.freq < b.freq;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}