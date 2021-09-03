class Solution {
    public int countPrimes(int n) {
        boolean[] is_Prime = new boolean[n + 1];
        int count = 0;
        
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
        
    }
}