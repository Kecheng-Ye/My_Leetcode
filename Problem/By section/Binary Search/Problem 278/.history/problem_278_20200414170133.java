/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

class Solution extends VersionControl {
        public int firstBadVersion(int n) {
            if(n <= 0) return 1;
            
            int ans = bin_search(n, 1, n);
            
            return (ans < 0) ? 1 : ans;
            
        }
        
        public int bin_search(int n, int l, int r){
            if(l <= r){
                int middle = l + (r - l) / 2;
                
                if(l == r){
                    return l;
                }else if(isBadVersion(middle)){
                    return bin_search(n, l, middle);
                }else{
                    return bin_search(n, middle + 1, r);
                }
            }else{
                return -1;
            }
        }
    
}