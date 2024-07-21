#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    class SegmentTreeNode {
    public:
        SegmentTreeNode(int _start, int _end, int _sum):  
            start(_start), end(_end), sum(_sum),
            left(nullptr), right(nullptr)
        {}

        SegmentTreeNode(
            int _start, int _end, int _sum, 
            SegmentTreeNode* _left, SegmentTreeNode* _right
        ):  
            start(_start), end(_end), sum(_sum),
            left(_left), right(_right)
        {}

        ~SegmentTreeNode() {
            delete left;
            delete right;
            left = right = nullptr;
        }

        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
    };
public:
    // Time: O(n)
    SegmentTree(const vector<int>& _nums): nums(_nums) {
        root = buildTree(0, nums.size() - 1);
    }

    // Time: O(logn)
    void update(const int idx, const int val) {
        updateHelper(root, idx, val);
    }

    // Time: O(logn + k)
    int queryRange(const int start, const int end) {
        return queryRangeHelper(root, start, end);
    }

private:
    SegmentTreeNode* buildTree(const int start, const int end) {
        if (start == end) {
            return new SegmentTreeNode(
                start, end, 
                nums[start]
            );
        }

        const int mid = start + (end - start) / 2;
        SegmentTreeNode* left = buildTree(start, mid);
        SegmentTreeNode* right = buildTree(mid + 1, end);
        return new SegmentTreeNode(
            start, end, 
            left->sum + right->sum,
            left, right
        );
    }

    void updateHelper(SegmentTreeNode* root, const int idx, const int val) {
        if (root->start == idx && root->end == idx) {
            root->sum = val;
            return;
        }

        const int mid = root->start + (root->end - root->start) / 2;
        if (idx <= mid) {
            updateHelper(root->left, idx, val);
        } else {
            updateHelper(root->right, idx, val);
        }

        root->sum = root->left->sum + root->right->sum;
    }

    int queryRangeHelper(SegmentTreeNode* root, const int start, const int end) {
        if (root->start == start && root->end == end) {
            return root->sum;
        }

        const int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return queryRangeHelper(root->left, start, end);
        } else if (start > mid) {
            return queryRangeHelper(root->right, start, end);
        } else {
            return queryRangeHelper(root->left, start, mid) + 
                   queryRangeHelper(root->right, mid + 1, end);
        }
    }

    SegmentTreeNode* root;
    vector<int> nums;
};

class NumArray {
public:
    NumArray(vector<int>& nums): tree(nums) {
        
    }
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.queryRange(left, right);
    }
private:
    SegmentTree tree;
};

int main(int argc, char** argv) {
    // NumArray* obj = new NumArray(nums);
    // obj->update(index,val);
    // int param_2 = obj->sumRange(left,right);
    
    return 0;
}