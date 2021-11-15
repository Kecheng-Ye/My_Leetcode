#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    TimeMap() : record(){
        
    }
    
    void set(string key, string value, int timestamp) {
        if(!record.count(key)) {
            record[key] = {{}, {}};
        }
        
        record[key].first.push_back(timestamp);
        record[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(!record.count(key)) return "";
        
        auto& [time, val] = record[key];
        
        int i = 0, j = time.size();
        
        while(i < j) {
            int mid = i + (j - i) / 2;
            
            if(time[mid] == timestamp) {
                return val[mid];
            }else if(time[mid] > timestamp) {
                j = mid;
            }else{
                i = mid + 1;
            }
        }
        
        return (i == 0) ? "" : val[i - 1];
    }
    
private:
    unordered_map<string, pair<vector<int>, vector<string>>> record;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}