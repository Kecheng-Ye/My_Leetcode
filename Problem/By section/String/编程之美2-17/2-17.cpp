#include <bits/stdc++.h>

using namespace std;

void reverse(string& s, int start, int end) {
    for(int i = 0; i <= (end - start) / 2; i++) {
        char temp = s[start + i];
        s[start + i] = s[end - i];
        s[end - i] = temp;
    }
}

// Time: O(n), Space: O(1)
void right_shift(string& s, int k) {
    int n = s.size();
    k %= n;

    reverse(s, 0, k - 1);
    reverse(s, k, n - 1);
    reverse(s, 0, n - 1);
}

int main(int argc, char** argv) {
    // Solution s;
    
    string s = "abcd1234";
    right_shift(s, 4);
    cout << s << endl;

    return 0;
}