class Solution {
    // Time: O(n), Space: O(1)
    // Greedy by just looking the empty spot and check whether the i - 1 and i + 1 position is empty or not
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        // if(flowerbed.length == 0 && n > 0) return false;
        
        // int i = 0;
        // while(i < flowerbed.length){
        //     if(flowerbed[i] == 1){
        //         if(i + 2 == flowerbed.length) break;
        //         i += 2;
        //     }else{
        //         if(((i - 1 < 0) ? true : flowerbed[i - 1] == 0) && (i + 1 < flowerbed.length) ? flowerbed[i + 1] == 0 : true){
        //             n --;
        //             if(i + 2 < flowerbed.length){
        //                 i += 2;
        //             }else{
        //                 break;
        //             }
        //         }else{
        //             i ++;
        //         }
        //     }
        // }
        // return n <= 0;

        int len = flowerbed.length;
        int cnt = 0;
        for (int i = 0; i < len && cnt < n; i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            int pre = i == 0 ? 0 : flowerbed[i - 1];
            int next = i == len - 1 ? 0 : flowerbed[i + 1];
            if (pre == 0 && next == 0) {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
}

public class problem_605{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.canPlaceFlowers(new int[]{0,1,0}, 1);
    }
}