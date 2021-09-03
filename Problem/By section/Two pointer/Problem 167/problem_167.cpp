#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Time O(n) Space: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            int result = numbers[i] + numbers[j];
            if(result == target) {
                return vector<int>{i + 1, j + 1};
            }else if(result > target) {
                j --;
            }else{
                i ++;
            }
        }

        return vector<int>{};
    }
};


int main(int argc, char** argv) {
    std::vector<int> marks = {2,7,11,15};
    Solution solution;
    vector<int> result = solution.twoSum(marks, 9);
    // cout << result.size() << endl;
    for(int i : result) {
        cout << i << endl;
    }
    return 0;

}