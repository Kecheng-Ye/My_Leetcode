#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        
        int sum=0;
        for(auto a : nums)
            sum += a;
        
        //If each side is not integer
        if(sum % 4) return false;
        int side = sum/4;

        //Optimize :Reverse sort so that bigger numbers get rejected early on in the expansion tree
        sort(nums.begin(),nums.end(), greater<int>());
        
        //Optimize: If any match is bigger than the expected side
        for(auto a : nums)
            if (a > side) return false;
        
        vector<int> sides(4,0);
        return dfs(nums, sides, 0, side);
    }
    
    bool dfs(vector<int>& match,vector<int>& sides,int index,int side){
        if(allSidesEqual(sides, side))
            return true;
        
        for(int i = 0; i < 4; i++)
        {
            //Optimize 1:
            if(sides[i] + match[index] > side)
                continue;
            
            //Optimize 2:
            // lets say sides are currently : [5,7,5,9] , the next element is 3.
            // Therefore we will be applying dfs on the following:
            // [5+3,7,5,9]
            // [5,7+3,5,9]
            // [5,7,5+3,9]
            // [5,7,5,9+3]
            // First and third are basically the same, only in a different order. 
            // If in the first case, dfs returned false, the third case will return false too.
            // So we don't run dfs in third case.
            if(seenBefore(sides, i))
                continue;
            
            sides[i] += match[index];
            if(dfs(match, sides, index+1, side)) return true;
            sides[i] -= match[index];

        }
        return false;
    }
    
    inline bool allSidesEqual(const vector<int>& sides, const int target){
        return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && sides[3] == target;
    }
    
    inline bool seenBefore(const vector<int>& sides,int i){
        return i==0 ? false:
               i==1 ? sides[1] == sides[0] :
               i==2 ? sides[2] == sides[1] || sides[2] == sides[0] :
               i==3 ? sides[3] == sides[2] || sides[3] == sides[1] || sides[3] == sides[0] : false;
            
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}