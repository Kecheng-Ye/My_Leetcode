public class problem10{
    

    // Will Fail!!!! Since this parsing cannot full fill the requirement of 
    // Ex: s: aaaaa p: a*a

    // public static boolean isMatch(String s, String p) {
    //     if(p.length() == 0) return false;
    //     char lookahead;
    //     char current_p;
    //     char previous_p;
    //     boolean need_prev = false;
    //     int i = 0;
    //     int j = 0;

    //     while(i < s.length()-1 && j < p.length()-1){
    //         current_p = p.charAt(j);
    //         previous_p = (j > 0) ? p.charAt(j - 1) : ' ';
    //         lookahead = s.charAt(i);
    //         if(current_p == '*'){
    //             need_prev = true;
    //         }

    //         //System.out.println("current_p: " + current_p + " previous_p: " + previous_p + " lookahead: " + lookahead + " need_prev: " + need_prev);

    //         switch(current_p){
    //             case '.':
    //                 //.out.println("meet . ");
    //                 i++;
    //                 break;
    //             case '*':
    //                 //System.out.println("meet * ");
    //                 if(previous_p == '.'){
    //                     System.out.println("prev is . ");
    //                     i++;
    //                 }else{
    //                     //System.out.println("prev is a specific cahr");
    //                     if(previous_p != lookahead){
    //                         if(p.charAt(j+1) == lookahead || p.charAt(j+1) == '.'){
    //                             need_prev = false;
    //                         }else{
    //                             return false;
    //                         }
    //                     }else i++;
    //                 }
    //                 break;
    //             default:
    //                 //System.out.println("meet char ");
    //                 if(current_p != lookahead){
    //                     if(p.charAt(j+1) == '*'){

    //                     }else{
    //                         return false;
    //                     }
    //                 }
    //                 else i++;
    //                 break;
    //         }
            
    //         lookahead = s.charAt(i);
    //         //System.out.println("lookahead: " + lookahead);
    //         if(need_prev && (previous_p == '.' || previous_p == lookahead)){
    //             //System.out.println("if * can still be iterate!");
    //             continue;
    //         }else{
    //             //System.out.println("* can no longer to iterate");
    //             need_prev = false;
    //             j++;
    //         }
    //         //System.out.println("i: "+ i + " j: "+ j);

    //     }

    //     return (i == s.length()-1 && j == p.length()-1);

    // }

    // recursive approach
    // public static boolean isMatch(String text, String pattern) {
    //     if (pattern.isEmpty()) return text.isEmpty();       // return true if both string has been consumed
    //     // Match the first string by specific character or '.'
    //     boolean first_match = (!text.isEmpty() &&
    //                            (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

    //     //important here
    //     //by meeting a '*', we can either repeat its previous char or entirly skip it
    //     if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
    //         return (isMatch(text, pattern.substring(2)) ||
    //                 (first_match && isMatch(text.substring(1), pattern)));
    //     } else {        //or we recurse to next level by cosuming both the char in s and p
    //         return first_match && isMatch(text.substring(1), pattern.substring(1));
    //     }
    // }

    //Dynamic Programing
    //dp[i][j] means the substring of s from 0 - i-1 can be matched by substring of p from 0 - j-1 
    public static boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        
        for(boolean[] i : dp){
            for(boolean j : i){
                j = false;
            }
        }

        int m = s.length();
        int n = p.length();

        //Initialization 
        //empty substring can only be matched by empty substring
        dp[0][0] = true;

        //empty pattern can not matched by any string
        for(int i = 1; i < m + 1; i++){
            dp[i][0] = false;
        }

        //empty string can not be matched by any pattern
        //except that the p[j - 1] = '*' 
        //then the dp[0][j] = dp [0][j -2], this means we regard * as a empty string  
        for(int j = 1; j < n + 1; j++){
            dp[0][j] = (j > 1) && (p.charAt(j - 1) == '*') && (dp[0][j - 2]);
        }

        //updating rule
        //if we encounter *
        //then we check if the previous char matched or we skipped the whole *
        //if we dont
        //we simply check if the previous matched or not
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(p.charAt(j - 1) == '*'){
                    dp[i][j] = (dp[i - 1][j] && (s.charAt(i - 1) == p.charAt(j - 2 ) || p.charAt(j - 2) == '.')) || 
                               (dp[i][j - 2]);
                }else{
                    dp[i][j] = (dp[i - 1][j - 1] && s.charAt(i - 1) == p.charAt(j - 1)) ||
                               (dp[i - 1][j - 1] && p.charAt(j - 1) == '.'); 
                }
            }
        }



        return dp[m][n];
    }





    public static void main(String[] args) {
        System.out.println(isMatch("bbbbb", "b*b"));
    }
}