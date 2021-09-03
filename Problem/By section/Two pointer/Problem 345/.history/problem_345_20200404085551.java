import java.util.*;
class problem_345 {
    public String reverseVowels(String s) {
        if(s.length() == 0) return null;
        if(s.length() == 1) return s;
        
        int i = 0;
        int j = s.length() - 1;
        char[] ans = s.toCharArray();
        HashSet<Character> Vowels = new HashSet<Character>();
        Vowels.add('a');
        Vowels.add('e');
        Vowels.add('i');
        Vowels.add('o');
        Vowels.add('u');
        // Vowels.addAll(Arrays.asList(new char[]{'a', 'e', 'i', 'o', 'u'}));
        // Collections.addAll(Vowels, new char[]{'a', 'e', 'i', 'o', 'u'});
        boolean left_flag = false;
        boolean right_flag = false;
        
        while(i < j){
            if(left_flag && right_flag){
                char temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
                left_flag = false;
                right_flag = false;
                i ++;
                j --;
            }else if(Vowels.contains(ans[i])){
                left_flag = true;
                j --;
            }else if(Vowels.contains(ans[j])){
                right_flag = true;
                i ++;
            }else{
                i ++;
                j --;
            }
        }
        
        return new String(ans);
    }
}