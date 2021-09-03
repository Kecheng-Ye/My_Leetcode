class Solution {
    public int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }

        boolean[] not_Prime = new boolean[n];
        int count = 0;
        
        // we will only need to iterate until n^0.5
        // since algo will atomatically update to n
        for(int i = 2; i < (int)Math.sqrt(n); i++){
            // if this number is actually a Prime number
            if(!not_Prime[i]){
                // update the count
                count ++;
                // will start from i^2
                // since there exist a smaller number k 
                // which alreday update k * i
                int temp = i * i;
                
                // and make all mutiple of this number to be not prime
                while(temp < n){
                    not_Prime[temp] = true;
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
        System.out.println(sol.countPrimes(9));
        // 2 3 5 7 11 13 
    }
}