class Solution {
    // Time: O(n), Space: O(1)
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        
        int buy_in = prices[0];
        int ans = 0;
        
        // whenever you encounter a low price, buy in
        // and sold out at the biggest value you can cell
        // iterate again
        for(int i = 1; i < prices.length; i ++){
            // checking for buy in value
            if(prices[i] < buy_in){
                buy_in = prices[i];
            }
            
            // checking for cell value
            int j = i;
            while(j + 1 < prices.length && prices[j + 1] >= prices[j]){
                j++;
            }

            // update the profit
            ans += prices[j] - buy_in;

            // when nothing can cell
            // break
            if(j < prices.length - 1){
                buy_in = prices[j + 1];
                i = j + 1;
            }else{
                break;
            }
        }

        return ans;
    }
}

public class problem_122{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxProfit(new int[]{1, 2, 3, 4, 5}));
    }
}