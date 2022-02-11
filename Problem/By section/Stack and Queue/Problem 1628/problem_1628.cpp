#include <bits/stdc++.h>

using namespace std;

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

using oper_func = function<int(const int, const int)>;

const unordered_map<string, oper_func> operators = {
	{"+" , [](const int a, const int b){return a + b;}},
	{"-" , [](const int a, const int b){return a - b;}},
	{"*" , [](const int a, const int b){return a * b;}},
	{"/" , [](const int a, const int b){return a / b;}},
};

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
// define your fields here
	Node *left;
	Node *right;
};


class Operator_Node : public Node {
public:
	Operator_Node(const string& oper_str, Node *left = nullptr, Node *right = nullptr) {
		if(!operators.count(oper_str)) {
			fprintf(stderr, "Non Recognizable operator \'%s\'", oper_str.c_str());
		}

		calculate = operators.at(oper_str);
		this->left = left;
		this->right = right;
	}

	int evaluate() const {
		return calculate(left->evaluate(), right->evaluate());
	}

private:
	oper_func calculate;
};


class Operand_Node : public Node {
public:
	Operand_Node(int val, Node *left = nullptr, Node *right = nullptr) {
		this->val = val;
		this->left = left;
		this->right = right;
	}

	int evaluate() const {
		return val;
	}

private:
	int val;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
		int n = postfix.size();
		stack<Node*> st;

		for(int i = 0; i < n; i++) {
			if(isdigit(postfix[i][0])) {
				Operand_Node *cur = new Operand_Node(stoi(postfix[i]));
				st.push(cur);
			}else{
				Operator_Node *cur = new Operator_Node(postfix[i]);
				Node* right = st.top();
				st.pop();
				Node* left = st.top();
				st.pop();

				cur->left = left;
				cur->right = right;
				
				st.push(cur);
			}
		}
		
		return st.top();
    }
};

int main(int argc, char** argv) {
    // Solution s;
    
    return 0;
}