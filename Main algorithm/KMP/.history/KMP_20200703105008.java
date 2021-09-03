public class KMP{
    private int[][] dp;
    private int M;
    public KMP(String pat){
        this.M = pat.length();
        dp = new int[M][256];
        int X = 0;

        dp[0][pat.charAt(0)] = 1;

        for(int i = 1; i < M; i++){
            for(int j = 0; j < 256; j ++){
                if((int)pat.charAt(i) == j){
                    dp[i][j] = i + 1;
                }else{
                    dp[i][j] = dp[X][j];
                }
            }
            X = dp[X][pat.charAt(i)];
        }
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


    public static void main(String[] args) {
        String pat = "abcbca";
        String txt = "bcabcbccabcbcc";
        KMP KMP = new KMP(pat);
        System.out.println(KMP.search(txt));

    }
}