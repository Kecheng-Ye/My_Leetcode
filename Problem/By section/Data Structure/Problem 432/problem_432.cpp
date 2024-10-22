#include <bits/stdc++.h>

using namespace std;

class AllOne {
private:
    struct Node {
        const int frequency;
        unordered_set<string> keys;
    };
    
    using NodePtr = list<Node>::iterator;
public:
    AllOne(): freqMap(), freqList() {

    }

    // Time: O(1)
    void inc(string key) {
        if (!freqMap.count(key)) {
            if (freqList.empty() || freqList.front().frequency != 1) {
                freqList.push_front({1, {}});
            }

            auto target = freqList.begin();
            freqMap[key] = target;
            target->keys.insert(key);
            return;
        }

        const auto ptr = freqMap[key];
        const auto target = findNodeAtNextTargetFreq(ptr->frequency + 1, ptr);
        moveValueFromOneNodeToOther(key, ptr, target);
        freqMap[key] = target;
    }

    // Time: O(1)
    void dec(string key) {
        const auto ptr = freqMap[key];

        if (ptr->frequency == 1) {
            freqMap.erase(key);
            removeValueFromOneNode(key, ptr);
        } else {
            const auto target = placeNodeAtPrevTargetFreq(ptr->frequency - 1, ptr);
            moveValueFromOneNodeToOther(key, ptr, target);
            freqMap[key] = target;
        }
    }

    // Time: O(1)
    string getMinKey() {
        if (freqList.empty()) return "";

        const auto minFrePtr = freqList.begin();
        return *((minFrePtr->keys).begin());
    }

    // Time: O(1)
    string getMaxKey() {
        if (freqList.empty()) return "";

        const auto maxFrePtr = freqList.rbegin();
        return *((maxFrePtr->keys).begin());
    }

private:
    void removeValueFromOneNode(const string& val, const NodePtr src) {
        src->keys.erase(val);
        if (src->keys.empty()) {
            freqList.erase(src);
        }
    }

    void moveValueFromOneNodeToOther(const string& val, const NodePtr src, const NodePtr dst) {
        dst->keys.insert(val);
        removeValueFromOneNode(val, src);
    }

    NodePtr findNodeAtNextTargetFreq (const int freq, const NodePtr ptr) {
        assert(ptr->frequency + 1 == freq);
        const auto nextPtr = next(ptr);
        if (nextPtr != freqList.end() && nextPtr->frequency == freq) return nextPtr;

        freqList.insert(next(ptr), {freq, {}});
        return next(ptr);
    }

    NodePtr placeNodeAtPrevTargetFreq (const int freq, const NodePtr ptr) {
        assert(ptr->frequency - 1 == freq);
        if (ptr == freqList.begin()) {
            freqList.push_front({freq, {}});
            return freqList.begin();
        }

        if (prev(ptr)->frequency < freq) {
            freqList.insert(ptr, {freq, {}});
            return prev(ptr);
        }

        assert(prev(ptr)->frequency == freq);
        return prev(ptr);
    }

    unordered_map<string, NodePtr> freqMap;
    list<Node> freqList;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(int argc, char** argv) {
    return 0;
}