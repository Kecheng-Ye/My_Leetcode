class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        
        int buy_in = prices[0];
        int ans = 0;
        
        for(int i = 1; i < prices.length - 1; i ++){
            if(prices[i] < buy_in){
                buy_in = prices[i];
            }
            System.out.println("buy in at " + buy_in);
            int j = i;
            while(j < prices.length && prices[j + 1] >= prices[j]){
                System.out.println("checking value " + prices[j]);
                j++;
            }
            System.out.println("sold out at " + prices[j]);
            ans += prices[j] - buy_in;

            buy_in = prices[j + 1];
            i = j + 1;
        }
        
        return ans;

    }
}

public class problem_122{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxProfit(new int[]{7, 1, 5, 3, 6, 4}));
    }
}