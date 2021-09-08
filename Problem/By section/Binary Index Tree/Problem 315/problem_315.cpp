#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Fenwick_Tree Approach
    // Time: O(nlogk), Space: O(k)
    vector<int> countSmaller(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        set<int> sorted(nums.begin(), nums.end()); // black red tree sorted
        unordered_map<int, int> ranks; 
        int start = 1;
        
        for(auto& i : sorted) { // rank should start at 1, because Fenwick_Tree start at 1
            ranks[i] = start++;    
        }
        
        int n = nums.size();
        Fenwick_Tree tree(n);
        vector<int> result(n, 0);
        
        for(int i = 0; i < n; i++) {
            int target = ranks[nums[i]];
            tree.Update(target, 1); // update all number start at [target, end]
            result[i] = tree.Query(target - 1); // count the current sum(0, target - 1)
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    class Fenwick_Tree {
    public:
        Fenwick_Tree(int size) {
            _sum = vector<int>(size + 1, 0);
        }
        
        
        void Update(int i, int val) {
            while(i < _sum.size()) {
                _sum[i] += val;
                i += lower_bit(i);
            }
        }
        
        int Query(int i) {
            int result = 0;
            while(i > 0) {
                result += _sum[i];
                i -= lower_bit(i);
            }
            
            return result;
        }
        
    private:
        int lower_bit(int num) {
            return num & (-num);
        }
        
        vector<int> _sum;
    };



// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         reverse(nums.begin(), nums.end());
//         int n = nums.size();
//         vector<int> result(n, 0);
//         BST* root = new BST(nums[0], 1, 0);
//         for(int i = 1; i < n; i++) {
//             result[i] = insert(root, nums[i]);
//         }
        
//         reverse(result.begin(), result.end());
//         delete root;
//         return result;
//     }

// BST approach
// private:
//     class BST {
//     public:
//         BST* left;
//         BST* right;
//         int val;
//         int frequency;
//         int left_count;
//         BST(int val, int frequency, int left_count): val(val), frequency(frequency), left_count(left_count), left(nullptr), right(nullptr){};
//         ~BST() {
//             delete left;
//             delete right;
//         }
//     };
    
//     int insert(BST* root, int val) {
//         if(root->val == val) {
//             root->frequency++;
//             return root->left_count;
//         }else{
//             if(val > root->val) {
//                 if(!root->right) {
//                     root->right = new BST(val, 1, 0);
//                     return root->left_count + root->frequency;
//                 }
                
//                 return root->left_count + root->frequency + insert(root->right, val);
                
//             }else{
//                 root->left_count++;
//                 if(!root->left) {
//                     root->left = new BST(val, 1, 0);
//                     return 0;
//                 }
                
                
//                 return insert(root->left, val);
//             }
//         }
//     }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}