#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "";
        
        string result = to_string(root->val);
        if((root->children).size()) {
            result += "[";
            for(int i = 0; i < (root->children).size(); i++) {
                Node* node = (root->children)[i];
                result += serialize(node);
                if(i < (root->children).size() - 1) result += " ";
            }
            result += "]";
        }
        
        return result;
        
    }
    
    int idx;
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        idx = 0;
        
        vector<Node*> temp;
        deserialize_helper(data, temp);
        return temp[0];
    }
    
    void deserialize_helper(string& data, vector<Node*>& children) {
        int n = data.size();
        if(!n) {
            children.push_back(nullptr);
            return;
        }
        Node* cur = new Node(getNum(data), {});
        children.push_back(cur);
        
        for(; idx < n; idx++) {
            if(data[idx] == ']') {
                return;
            }else if(data[idx] == ' ') {
                continue;
            }else if(data[idx] == '[') {
                idx++;
                deserialize_helper(data, cur->children);
            }else{
                cur = new Node(getNum(data), {});
                idx--;
                children.push_back(cur);   
            }
        }
        
    }
    
    int getNum(string& data) {
        int start = idx; 
        while(isdigit(data[++idx]))
            ;
        
        return stoi(data.substr(start, idx - start));
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}