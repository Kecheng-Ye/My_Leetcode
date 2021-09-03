class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(flowerbed.length == 0 && n > 0) return false;
        
        int i = 0;
        while(i + 1 < flowerbed.length){
            if(flowerbed[i] == 1){
                if(i + 2 = flowerbed.length) break;
                i += 2;
            }else{
                if(flowerbed[i + 1] == 0 && i + 2 < flowerbed.length){
                    i += 2;
                    n --;   
                }else{
                    i ++;
                }
            }
        }
        
        return n <= 0;
    }
}

public class problem_6