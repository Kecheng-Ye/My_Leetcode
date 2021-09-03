#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int>& vec);

class Solution {
public:
    unordered_map<string, vector<int>> reminder;

    vector<int> diffWaysToCompute(string expression) {
        if(expression.length() == 0) {
            return vector<int>{0};
        }if(reminder.count(expression)) {
            return reminder[expression];
        }else{
            vector<int> result;
            bool meet_operator = false;

            for(auto i = begin(expression); i != end(expression); i++) {
                if(*i == '+' || *i == '-' || *i == '*' || *i == '/') {
                    meet_operator = true;
                    vector<int> left = diffWaysToCompute(string(begin(expression), i));
                    vector<int> right = diffWaysToCompute(string(i + 1, end(expression)));

                    calculate(left, right, result, *i);
                }
            }

            result = (!meet_operator) ? vector<int>{stoi(expression)} : result;
            reminder[expression] = result;

            return result;
        }
    }

    void calculate(vector<int>& left, vector<int>& right, vector<int>& result, char expression) {
        for(auto& i : left) {
            for(auto& j : right) {
                int single_result;

                switch(expression) {
                    case '+':
                        single_result = i + j;
                        break;
                    case '-':
                        single_result = i - j;
                        break;
                    case '*':
                        single_result = i * j;
                        break;
                    case '/':
                        single_result = i / j;
                        break;
                }

                result.push_back(single_result);
            }
        }
    }
};

void print_vec(vector<int>& vec) {
    for(auto i : vec) {
        cout << i << " ";
    }

    cout << endl;
}

int main(int argc, char** argv) {
    Solution s;
    char test = 'a';
    string a = "11";
    auto result = s.diffWaysToCompute(a);
    print_vec(result);
    return 0;
}