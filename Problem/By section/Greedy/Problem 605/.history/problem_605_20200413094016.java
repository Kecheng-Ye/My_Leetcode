class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(flowerbed.length == 0 && n > 0) return false;
        
        int i = 0;
        while(i < flowerbed.length){
            System.out.println("Now at " + i);
            if(flowerbed[i] == 1){
                if(i + 2 == flowerbed.length) break;
                i += 2;
            }else{
                if(flowerbed[i - 1] == 0|| flowerbed[i + 1] == 0){
                    n --;
                    if(i + 2 < flowerbed.length) i += 2;
                }else{
                    i ++;
                }
            }
        }
        System.out.println("n = " + n);
        return n <= 0;
    }
}

public class problem_605{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.canPlaceFlowers(new int[]{1,0,1,0,0}, 1);
    }
}