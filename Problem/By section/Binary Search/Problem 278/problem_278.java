/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

class Solution extends VersionControl {
    // Time: O(log(n)), Space: O(1)
    public int firstBadVersion(int n) {
        if(n <= 0) return 1;
        
        return bin_search(n, 0, n);
        
    }
    
    public int bin_search(int n, int l, int r){
        int middle = l + (r - l) / 2;
        
        if(l == r){
            return l;
        }else if(isBadVersion(middle)){
            // if we know the middle one is bad, we know that the first bad version can be in [l, l + 1,..., middle]
            return bin_search(n, l, middle);
        }else{
            // else then the bad vision can only happen in [middle + 1,..., r]
            return bin_search(n, middle + 1, r);
        }
    }
}