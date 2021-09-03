import java.util.*;
class Solution{
    private final static HashSet<Character> Vowels = new HashSet<>(
        Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
    
    public static String reverseVowels(String s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;
        
        int i = 0;
        int j = s.length() - 1;
        char[] ans = s.toCharArray();
        while(i < j){
            if(Vowels.contains(ans[i]) && Vowels.contains(ans[j])){
                char temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
                i ++;
                j --;
            }else if(Vowels.contains(ans[i])){
                j --;
            }else if(Vowels.contains(ans[j])){
                i ++;
            }else{
                i ++;
                j --;
            }
        }
        
        return new String(ans);
    }

}