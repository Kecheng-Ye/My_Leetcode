class Solution {
    public int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }

        boolean[] not_Prime = new boolean[n];
        int count = 0;
        
        // we will only need to iterate until n^0.5
        // since algo will atomatically update to n
        for(int i = 2; i <= (int)Math.sqrt(n); i++){
            // if this number is actually a Prime number
            if(!not_Prime[i]){
                // will start from i^2
                // since there exist a smaller number k 
                // which alreday update k * i
                int temp = i * i;
                
                // and make all mutiple of this number to be not prime
                while(temp < n){
                    temp += i;
                    if(not_Prime[temp]) continue;
                    not_Prime[temp] = true;
                    count ++;
                }

            }else{
                continue;
            }
        }

        return n - 2 - count;
    }
}

public class problem_204{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println("answer is " + sol.countPrimes(13));

    }
}