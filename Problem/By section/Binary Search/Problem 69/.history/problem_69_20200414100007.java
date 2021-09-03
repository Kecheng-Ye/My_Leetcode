class Solution {
    // Time: O(log(n)), Space: O(1)
    public int mySqrt(int x) {
        return bin_search(x, 0, x);
    }
    
    // use binary search to track
    public int bin_search(int x, int l, int r){
        // middle point's index is very important
        int middle = l + (r - l) / 2;
        
        // since we sometimes can not have a perfect sqrt
        // so we have to check two condition
        // eg. sqrt(8) = 2, 2^2 < 8 && 3^2 > 8
        if(Math.pow(middle,2) <= x && Math.pow(middle + 1,2) > x){
            return middle;
        }else if(Math.pow(middle,2) < x){
            return bin_search(x, middle + 1, r);
        }else{
            return bin_search(x, l, middle - 1);
        }
    }
}