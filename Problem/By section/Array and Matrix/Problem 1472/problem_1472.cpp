#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
public:
    // Space: O(n)
    BrowserHistory(string homepage): history(), cur_tab(0), size(1) {
        history.push_back(homepage);
    }

    // Time: O(1)
    void visit(string url) {
        if (cur_tab != size - 1) {
            size = cur_tab + 2;
            history[cur_tab + 1] = url;
        } else {
            if (size == history.size()) {
                history.push_back(url);
            } else {
                history[size] = url;
            }

            size++;
        }

        cur_tab++;
    }

    // Time: O(1)
    string back(int steps) {
        int target = (cur_tab >= steps) ? cur_tab - steps : 0;
        cur_tab = target;
        return history[cur_tab];
    }

    // Time: O(1)
    string forward(int steps) {
        int target = ((size - cur_tab) > steps) ? cur_tab + steps : size - 1;
        cur_tab = target;
        return history[cur_tab];
    }


private:
    vector<string> history;
    int cur_tab;
    int size;

    void log() {
        printf("size: %d, cur tab: %d\n", size, cur_tab);
        printf("Tabs: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", history[i].data());
        }
        printf("\n");
    }
};

int main(int argc, char** argv) {
    return 0;
}
