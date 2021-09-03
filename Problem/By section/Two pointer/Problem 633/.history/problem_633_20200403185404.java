
class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0;
        int j = (int)(Math.pow(c, 0.5));
        
        while(i <= j){
            int temp = (int)(Math.pow(i, 2) + Math.pow(j, 2));
            if(temp == c){
                return true;
            }else if(temp > c){
                j --;
            }else{
                i ++;
            }
        }
        
        return false;
    }
}