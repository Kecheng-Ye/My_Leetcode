#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
    // Time: O(1), Space: O(n)
    ProductOfNumbers(): prefix_product(1, 1), size(0) {
        
    }
    
    void add(int num) {
        if(num == 0) {
            // trick here
            // clear all the prefix arr to solve the overflow issue
            prefix_product.clear();
            prefix_product.push_back(1);
            size = 0;
        }else{
            prefix_product.push_back(prefix_product.back() * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k > size) {
            return 0;
        }else{
            return prefix_product.back() / prefix_product[size - k];
        }
    }
    
private:
    vector<long long> prefix_product;
    int size;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(int argc, char** argv) {
    
    return 0;
}