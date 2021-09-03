class Solution {
    public int countPrimes(int n) {
        if(n <= 1){
            return 0;
        }

        boolean[] is_Prime = new boolean[n + 1];
        int count = 0;
        
        for(int i = 2; i <= n; i++){
            if(!is_Prime[i]){
                count ++;
                int temp = i;
                
                while(temp <= n){
                    is_Prime[temp] = true;
                    temp += i;
                }

            }else{
                continue;
            }
        }

        return count;
    }
}

public class problem_204{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countPrimes(11));
        // 2 3 5 7 
    }
}