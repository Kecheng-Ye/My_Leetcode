import java.util.*;
class Solution {
    // dp[i] = the min amount of coins that can sum up to i
    // update rule
    // dp[i] = min(dp[i], dp[i - each_coin] + 1)
    // meaning for each type of coin, we will either use it or don't use it
    private int[] dp;
   
    // n: amount, m: coins.length
    // Time: O(n * m), Space: O(n)
    public int coinChange(int[] coins, int amount) {
        if(coins.length == 0) return -1;

        Arrays.sort(coins);
        
        dp = new int[amount + 1];
        // trick here
        // we cannot simply use Integer.MAX_VALUE here
        // because it will result in overflow
        Arrays.fill(dp, amount + 1);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin < 0) break;
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
}