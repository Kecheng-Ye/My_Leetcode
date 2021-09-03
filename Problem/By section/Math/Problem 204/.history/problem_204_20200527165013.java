class Solution {
    public int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }

        boolean[] is_Prime = new boolean[n];
        int count = 0;
        

        for(int i = 2; i < (int)Math.sqrt(n); i++){
            if(!is_Prime[i]){
                count ++;
                int temp = i * i;
                
                while(temp < n){
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
        System.out.println(sol.countPrimes(13));
        // 2 3 5 7 11 13 
    }
}