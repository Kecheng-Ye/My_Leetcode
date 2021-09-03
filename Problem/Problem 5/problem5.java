public class problem5{
    
    
    //Will fail!!!!!!! 
    //since I cannot haddle the case such that T[i] is not related to T[i-1] 
    //EX: anana   T[2] = ana, T[3]=nan
    // Dynamic Programing
    //T[i] = the length of the longest palindromic substring ending with s[i]
    // public static String longestPalindrome(String s) {
    //     // if(s.length() == 0) return "";

    //     // int[] dp_arr = new int[s.length()];
    //     // dp_arr[0] = 1;
    //     // int[] max_length = {0,1};              //ans = [start_index, substring_length]
    //     // for(int i = 1; i < s.length(); i++){
    //     //     System.out.println("index: " + i);
    //     //     int if_Palindrome = 1;
    //     //     if(i- 1 - dp_arr[i-1] >= 0){
    //     //         // if_Palindrome = (s.charAt(i- 1 - dp_arr[i-1]) == s.charAt(i)) ? dp_arr[i-1] + 2 : 1;
    //     //         if_Palindrome = (s.charAt(i- 1 - dp_arr[i-1]) == s.charAt(i)) ? dp_arr[i-1] + 2 : 1;
    //     //     }
    //     //     if_Palindrome = Math.max(if_Palindrome, (s.charAt(i- 1) == s.charAt(i)) ? dp_arr[i-1] + 1 : 1);
    //     //     System.out.println("if_Palindrome["  + i + "] = " + if_Palindrome);
    //     //     dp_arr[i] = Math.max(1, if_Palindrome);
    //     //     System.out.println("dp_arr[" + i + "] = " + dp_arr[i]);
    //     //     if(dp_arr[i] > max_length[1]){
    //     //         max_length[0] = i;
    //     //         max_length[1] = dp_arr[i];
    //     //     }

    //     // }

    //     // return s.substring(max_length[0] - max_length[1] + 1, max_length[0]+1);


    // }


    /********************/
    //check the Palindrome by checking the max Palindrome expanded in each center
    //there will be 2n-1 center instead of n becuase
    //there will be a Palindrome with even number of length : abba
    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {         // iterate over n possible index
            int len1 = expandAroundCenter(s, i, i);     //check the possible Palindrome expanding from the center i
            int len2 = expandAroundCenter(s, i, i + 1); //check the possible Palindrome expanding from the center between i and i+1 
            int len = Math.max(len1, len2);
            if (len > end - start) {                    //if the current possible Palindrome is greater than the previous max
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }
    
    private static int expandAroundCenter(String s, int left, int right) {     // the function for expanding
        int L = left, R = right;
        //a Palindrome is valid only when the left most char and right most char are equal
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {    
            L--;
            R++;
        }
        return R - L - 1;
    }

    //dynamic programing
    //T[i][j] = is the substring from i to j a valid palindrome
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 2) return s;
        boolean[][] dp = new boolean[s.length()][s.length()];
        int row = 0, col = 0;
        for (int i = s.length() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j) && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > col - row + 1) {
                        row = i;
                        col = j;
                    }
                }

            }
        }
        return s.substring(row, col + 1);
    }

    
    public static void main(String[] args) {
        System.out.println(longestPalindrome("anana"));
        // System.out.println("abc".substring(1,2));
    }
}