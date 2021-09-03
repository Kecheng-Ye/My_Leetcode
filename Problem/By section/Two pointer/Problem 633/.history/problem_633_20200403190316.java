
class Solution {
    // time: O(sqrt(c)), space: O(1)
    public boolean judgeSquareSum(int c) {
        if(c < 0) return false;
        
        //two pointer, one starts with 0 and the other starts with sqrt(c)
        int i = 0;
        int j = (int)(Math.pow(c, 0.5));
        
        while(i <= j){
            int temp = (int)(Math.pow(i, 2) + Math.pow(j, 2));
            //if the sum = c
            if(temp == c){
                return true;
            }else if(temp > c){
                // if the sum is bigger than c
                // we will decrement the right pointer
                j --;
            }else{
                // if the sum is smaller than c
                // we will increment the left pointer
                i ++;
            }
        }
        
        return false;
    }
}