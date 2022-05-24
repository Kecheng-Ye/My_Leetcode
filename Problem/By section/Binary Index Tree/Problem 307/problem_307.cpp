#include <bits/stdc++.h>

using namespace std;

class Fenwick_Tree {
public:
    Fenwick_Tree() {}

    Fenwick_Tree(int size) {
        _sum = vector<int>(size + 1, 0);
    }


    void Update(int i, int val) {
        while(i < _sum.size()) {
            _sum[i] += val;
            i += lower_bit(i);
        }
    }

    int Query(int i) {
        int result = 0;
        while(i > 0) {
            result += _sum[i];
            i -= lower_bit(i);
        }

        return result;
    }

private:
    int lower_bit(int num) {
        return num & (-num);
    }

    vector<int> _sum;
};


class NumArray {
public:
    // Time: O(nlogn), Space: O(n)
    NumArray(vector<int>& nums){
        int n = nums.size();
        tree = Fenwick_Tree(n);
        nums_ = vector<int>(std::move(nums)); 
            
        for(int i = 0; i < n; i++) {
            tree.Update(i + 1, nums_[i]);
        }
    }
    
    // Time: O(logn), Space: O(1)
    void update(int index, int val) {
        tree.Update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    // Time: O(logn), Space: O(1)
    int sumRange(int left, int right) {
        return tree.Query(right + 1) - tree.Query(left);
    }

private:
    Fenwick_Tree tree;
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}