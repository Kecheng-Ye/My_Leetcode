public class KMP{
    private int[][] dp;
    private int M;
    public KMP(String pat){

    }

    public int search(String txt){
        int n = txt.length();
        int state = 0;
        for(int i = 0; i < n; i++){
            state = dp[state][txt.charAt(i)];
            if(state == M){
                return i - M + 1;
            }
        }

        return -1;
    }

}