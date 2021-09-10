#include <bits/stdc++.h>

using namespace std;

class FenwickTree
{
    public:
        vector<int>tree;
        
        FenwickTree(int n)
        {
            tree.resize(n,0);
        }
    
        // update value from i to 0
        void update(int i, int val)
        {
            while(i>0)
            {
                tree[i]+=val;
                i-= i&-i;
            }
        }
    
        // get value from i to range
        int get(int i)
        {
            int val = 0;
            while(i<tree.size())
            {
                val+= tree[i];
                i+= i&-i;
            }
            
            return val;
        }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
    
        int n = nums.size();
        
        // store all nums[i] and 2 * nums[i] in the Map
        map<long long int,int>vals;
        for(int i=0;i<n;i++)vals[(long long int)nums[i]]=0;
        for(int i=0;i<n;i++)vals[(long long int)nums[i]*2L]=0;
        
        int m = 2*n;
        int k = 0;
        
        // update the rank of all numbers starting from 1
        for(auto &t : vals)
            t.second = ++k;      
        
        // make a BIT with max size m == 2n
        FenwickTree tree(m+1);
        
        int c = 0;
        
        // loop from 0 to n and get the rank count greater than Map[2 * nums[i] + 1]
        // also update value for rank Map[nums[i]]
        for(int i=0;i<n;i++)
        {            
            c+= tree.get(vals[(long long int)nums[i] * 2L] + 1);
            tree.update(vals[(long long int)nums[i]],1);
        }
        
        return c;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}