#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;

            if(letters[mid] == target) {
                left = mid + 1;
            }else if(letters[mid] < target) {
                left = mid + 1;
            }else if(letters[mid] > target) {
                right = mid - 1;
            }
        }

        if(left > letters.size() - 1) {
            return letters[0];
        }else{
            return letters[left];
        }

    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<char> input = {'c', 'd', 'd', 'f'};
    char target = 'd';
    cout << s.nextGreatestLetter(input, target) << endl;
    return 0;
}