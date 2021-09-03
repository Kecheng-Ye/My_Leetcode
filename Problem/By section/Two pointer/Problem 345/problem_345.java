import java.util.*;
class Solution{
    // use HashSet to achieve O(1) for determining whether a letter is a vowel
    private final static HashSet<Character> Vowels = new HashSet<>(
        Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
    
    // time: O(s.length), space: O(1)
    public static String reverseVowels(String s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;
        
        //two pointers
        int i = 0;
        int j = s.length() - 1;
        char[] ans = s.toCharArray();
        while(i < j){
            char temp_1 = ans[i];
            char temp_2 = ans[j];
            
            // find the left i that is a voewl
            if(!Vowels.contains(temp_1)){
                i ++;
            }else if(!Vowels.contains(temp_2)){
                // find right j that is a voewl
                j --;
            }else{
                // swap them, and continue
                ans[i ++] = temp_2;
                ans[j --] = temp_1;
            }
        }
        
        return new String(ans);
    }

}