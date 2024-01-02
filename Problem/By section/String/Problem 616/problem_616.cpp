#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }

    // Time: O(nm), Space: O(n)
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        if(!words.size()) return s;

        vector<pair<int, int>> intervals;
        // find potential interval
        for(const auto& word : words) {
            findAllOccurrenceOfTargetString(s, word, intervals);
        }

        if(!intervals.size()) return s;

        // merge interval
        const vector<pair<int, int>> result = mergeInterval(intervals);

        // construct final string by both inserting the target string and those strings that are not in the list
        string final_str = s.substr(0, result[0].first);
        int start, end;
        int next_start;
        for(int i = 0; i < result.size(); i++) {
            start = result[i].first;
            end  = result[i].second;
            next_start = (i == result.size() - 1) ? n : result[i + 1].first;
            final_str += "<b>" + s.substr(start, end - start) + "</b>";
            if(next_start != end) final_str += s.substr(end, next_start - end);
        }


        return final_str;

    }

    void findAllOccurrenceOfTargetString(const string& s, const string& word, vector<pair<int, int>>& intervals) {
        int n = s.size();
        int size = word.size();
        int i = 0;
        while(i <= n - size) {
            int start = s.find(word, i);
            if(start == string::npos) break;
            int end = start + size;
            intervals.push_back({start, end});
            i = start + 1;
        }
    }

    vector<pair<int, int>> mergeInterval(vector<pair<int, int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<pair<int, int>> result;

        int start = intervals[0].first, end = intervals[0].second;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].first <= end) {
                end = max(end, intervals[i].second);
            }else{
                result.push_back({start, end});
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        result.push_back({start, end}); // remember to add final start and end

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
