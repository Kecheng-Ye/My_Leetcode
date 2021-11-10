#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // First part: we only care about if a letter is odd or even count, so we can track the current state of the string from [0...i] using a bitmask. 1 will mean that character is odd and 0 will mean that character is even. For example, "1001" means d has odd count, c even, b even, a odd

    // To calculate the answer: We go through from index 0 to the length of the string, updating the state of the string from [0...current index]. If we have seen our current state before (say [0...j] has the same state as [0...i], that means the substring between j and i has an even count of all characters. Think about each new character as flicking it's own light switch. Flicking a switch an even amount of times results in no change. So if we see that we have previously run into the current state, we know there is a substring with even count of all characters in between that state and the current state. We add however many times we have previously run into the current state. This is because if we've run into the state once before, say at j, we know [j...current index] has even count of all characters. So we add 1 to our answer. If we've run into the state twice before, say at j and i, we know that [j... current index] has even count of all characters and [i...current index] has even count of all characters, so we add 2.

    // Next we tackle the part where one character can be odd. If there is one character which occurs an odd amount of times between [previous index... current index], and all other characters are even, that means we only need to flick one switch to turn our current state into the previous one. We try flicking each switch and see if we have run into that state before. If we have that means we have a wonderful substring because only 1 character appears an odd number of times between [previous index... current index]. Again we add the number of times we have previously run into the state, because of the same reason as above. If we've seen the state at j, then [j...current] has only 1 odd character, and if we've seen it at j and i, then [j...current] and [i...current] have only 1 odd character, etc.
    
    // Time: O(n), Space: O(n)
    long long wonderfulSubstrings(string word) {
        vector<int> cnt(1024);
        cnt[0] = 1;  //empty string gives case where all characters occur even number of times
        int mask = 0; // current state
        long ans = 0;
        
        for (char c : word) {
            int idx = c - 'a';
            mask ^= 1 << idx; // update state
            ans += cnt[mask]; // add count of same previous states
            for (int i = 0; i < 10; i++) {
                int lookFor = mask ^ (1 << i); // try flick each switch
                ans += cnt[lookFor];
            }
            cnt[mask]++; // add 1 to count of times we've seen current state
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}