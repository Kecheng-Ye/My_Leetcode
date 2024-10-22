#include <bits/stdc++.h>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


// class NestedIterator {
// public:
//     NestedIterator(vector<NestedInteger> &nestedList): flattenList(), curr(0) {
//         traverseNestedList(nestedList);
//         size = flattenList.size();
//     }
    
//     int next() {
//         return flattenList[curr++];
//     }
    
//     bool hasNext() {
//         return curr < size;
//     }

// private:
//     void traverseNestedList(const vector<NestedInteger> &nestedList) {
//         if (nestedList.empty())
//             return;

//         for (const NestedInteger& item : nestedList) {
//             if (item.isInteger()) {
//                 flattenList.push_back(item.getInteger());
//             } else {
//                 traverseNestedList(item.getList());
//             }
//         }
//     }

//     vector<int> flattenList;
//     int size;
//     int curr;
// };

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList): st() {
        st.push({0, nestedList});
    }

    int next() {
        hasNext();
        auto& [idx, lst] = st.top();
        return lst[idx++].getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto& [idx, lst] = st.top();

            if (idx == lst.size()) {
                st.pop();
            } else {
                const auto& item = lst[idx];
                if (item.isInteger()) return true;
                idx++;
                st.push({0, item.getList()});
            }
        }

        return false;
    }

private:
    stack<pair<int, vector<NestedInteger>>> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv) {    
    return 0;
}