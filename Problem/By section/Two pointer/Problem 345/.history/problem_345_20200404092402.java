import java.util.*;
class Solution{
    private final static HashSet<Character> Vowels = new HashSet<>(
        Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
    
    public static String reverseVowels(String s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;
        
        //two pointers
        int i = 0;
        int j = s.length() - 1;
        char[] ans = s.toCharArray();
        while(i < j){
            // if both letters are voewls, swap them
            if(Vowels.contains(ans[i]) && Vowels.contains(ans[j])){
                char temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
                i ++;
                j --;
            }else if(Vowels.contains(ans[i])){
                // if the left letter is voewl, decrement right pointer
                j --;
            }else if(Vowels.contains(ans[j])){
                // if the right letter is voewl, increment right pointer
                i ++;
            }else{
                // both letters are not voewls
                i ++;
                j --;
            }
        }
        
        return new String(ans);
    }

}