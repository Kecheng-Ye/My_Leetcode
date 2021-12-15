#include <bits/stdc++.h>

using namespace std;

extern int rand7();

class Solution {
public:
    // for randX() to randY() function
    // first find a number X' which is bigger than Y and is X^n
    // then sample from X', reject any part of sample that is greater than Y
    // take the remaining sample, mod with Y
    // Time: O(2.45), Space: O(1)
    int rand10() {
        return rand40() % 10 + 1;
    }
    
    int rand40() {
        int rand49;
        
        do{
            rand49 = (rand7() -1) * 7 + (rand7() - 1);
        }while(rand49 >= 40);
        
        return rand49;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}