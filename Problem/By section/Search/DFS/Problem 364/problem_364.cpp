#include <bits/stdc++.h>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:    
    // Constructor initializes an empty nested list.     
    NestedInteger();
    
    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    // Time: O(n), Space: O(depth)
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        const int maxDepth = getMaxDepth(nestedList);

        return depthSumInverseHelper(nestedList, 1, maxDepth);
    }

private:
    int depthSumInverseHelper(const vector<NestedInteger>& nestedList, const int currDepth, const int maxDepth) {
        if (nestedList.size() == 0) return 0;

        int result = 0;

        for (const NestedInteger& item : nestedList) {
            if (item.isInteger()) {
                result += item.getInteger() * (maxDepth - currDepth + 1);
            } else {
                result += depthSumInverseHelper(item.getList(), currDepth + 1, maxDepth);
            }
        }

        return result;
    }

    int getMaxDepth(const vector<NestedInteger>& nestedList) {
        if (nestedList.size() == 0) return 0;

        int maxDepth = 0;

        for (const NestedInteger& item : nestedList) {
            if (item.isInteger()) {
                maxDepth = max(maxDepth, 1);
            } else {
                maxDepth = max(maxDepth, 1 + getMaxDepth(item.getList()));
            }
        }

        return maxDepth;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}