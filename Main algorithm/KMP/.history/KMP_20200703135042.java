public class KMP{
    // dp arr is basically a dfa(determinstic finite atomda)
    // dp[i][j] means what state will the machine go when currently at state i meeting character j
    private int[][] dp;
    private int M;

    // Time: O(M), Space: O(M)
    public KMP(String pat){
        this.M = pat.length();
        dp = new int[M][256];
        // X is the shadow state
        int X = 0;
        // base case
        // when at initial state(0) meeting the first character of the pattern
        // the machine will transfer to state 1
        dp[0][pat.charAt(0)] = 1;

        // from state 1 to the end state 
        for(int i = 1; i < M; i++){
            // in every state, we will calculate the transition for every input character 
            for(int j = 0; j < 256; j ++){
                // if the character is the next char in the pattern
                // go to another state
                if((int)pat.charAt(i) == j){
                    dp[i][j] = i + 1;
                }else{
                    // else go to the shadow state
                    // and transfer to corrseponding state
                    dp[i][j] = dp[X][j];
                }
            }
            // update the shadow state 
            X = dp[X][pat.charAt(i)];
        }
    }

    // Time: O(N), Space: O(1)
    public int search(String txt){
        int n = txt.length();
        int state = 0;
        // iterate the input txt
        for(int i = 0; i < n; i++){
            // use the dp array to go to correct state
            state = dp[state][txt.charAt(i)];
            // if we reach the end of the state
            // return index
            if(state == M){
                return i - M + 1;
            }
        }
        // else, we cannot match the string pattern 
        return -1;
    }


    public static void main(String[] args) {
        String pat = "abcbca";
        String txt = "bcabcbccabcbcc";
        KMP KMP = new KMP(pat);
        System.out.println(KMP.search(txt));

    }
}