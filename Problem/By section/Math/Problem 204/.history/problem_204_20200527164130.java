class Solution {
    public int countPrimes(int n) {
        if(n <= 0){
            return 0;
        }else if(n <= 2){
            return n;
        }

        boolean[] is_Prime = new boolean[n + 1];
        int count = 1;
        
        for(int i = 2; i <= n; i++){
            if(!is_Prime[i]){
                count ++;
                int temp = i;
                
                while(temp <= n){
                    is_Prime[temp] = true;
                    temp += temp;
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
        System.out.println(sol.countPrimes(10));
    }
}